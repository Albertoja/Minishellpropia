/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:13:02 by magonzal          #+#    #+#             */
/*   Updated: 2023/03/20 17:53:59 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	select_redirection_pipex(t_all *aux, int *pip, int out)
{
	int	i;

	i = -1;
	while (aux->files && aux->files[++i])
	{
		if (aux->dir[i] == '2')
			pipexoutpuredirection(aux, i);
		else if (aux->dir[i] == '1')
			pipexinputredirection(aux, i);
		else if (aux->dir[i] == '4')
			pipexappendredirection(aux, i);
		else if (aux->dir[i] == '3')
			heredocpip(aux, out);
	}
	if (aux->next != NULL && (!ft_strchr(aux->dir, '2')
			&& !ft_strchr(aux->dir, '4')))
		dup2(pip[1], STDOUT_FILENO);
	else if (!ft_strchr(aux->dir, '2')
		&& !ft_strchr(aux->dir, '4'))
		dup2(out, STDOUT_FILENO);
}

void	childprocess(t_pxstrt s, int *pip)
{
	int	out;

	out = dup(STDOUT_FILENO);
	select_redirection_pipex(s.head, pip, out);
	close(pip[0]);
	close(pip[1]);
	if (is_builtin(s.head->cmds[0]) == 1)
	{
		ft_builtins(s.head, s.env, s.status, s.home);
		exit(0);
	}
	if (execve(get_path(s.head->cmds[0], s.env), s.head->cmds, s.env) == -1)
	{
		ft_error("EPX : command not found", s.head->cmds[0]);
		exit(127);
	}
}

t_pxstrt	definepxstrt(t_all *head, char **env, int *status, char *home)
{
	t_pxstrt	pxstrt;

	pxstrt.env = env;
	pxstrt.head = head;
	pxstrt.status = status;
	pxstrt.home = home;
	return (pxstrt);
}

void	pipex(t_all *head, char **envp, int *status, char *home)
{
	int			pip[2];
	t_all		*aux;
	t_pxstrt	pxstrt;
	pid_t		pid;

	aux = head;
	while (aux)
	{
		pipe(pip);
		pid = fork();
		if (pid == -1)
			ft_error("ERROR: error on Fork", "\n");
		if (pid == 0)
		{
			pxstrt = definepxstrt(aux, envp, status, home);
			childprocess(pxstrt, pip);
		}
		if (aux->next != NULL)
			dup2(pip[0], STDIN_FILENO);
		close(pip[0]);
		close(pip[1]);
		aux = aux->next;
	}
	close(STDIN_FILENO);
	waitpid(pid, status, 0);
}
