/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:51:39 by aespinos          #+#    #+#             */
/*   Updated: 2022/11/03 18:30:26 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*ret;
	int		len;

	len = 1;
	ret = NULL;
	while (1)
	{
		ret = malloc(sizeof(char) * len);
		if (getcwd(ret, len) == NULL)
			free(ret);
		else
			break ;
		len++;
	}
	printf("%s\n", ret);
	return (0);
}

void	ft_exit(char **str)
{
	int	env;
	int	cont;

	cont = 0;
	if (!str[1])
		exit(0);
	while (str[1][cont])
	{
		if (str[1][0] == '-' || str[1][cont] < '0' ||
			str[1][cont] > '9' || ft_strlen(str[1]) >= 19)
		{
			if (str[1][0] != '-' && str[1][cont] == '-')
			{
				printf("minishell: exit: %s:", str[1]);
				printf("numeric argument required\n");
				exit(255);
			}
		}
		cont++;
	}
	if (str[1][0] == '-' && ft_strncmp("-9223372036854775808", str[1], 21) < 0)
		printf("minishell: exit: %s: numeric argument required\n", str[1]);
	else if (str[1][0] != '-' &&
			ft_strncmp("9223372036854775807", str[1], 21) < 0)
		printf("minishell: exit: %s: numeric argument required\n", str[1]);
	env = ft_atoi(str[1]);
	exit(env);
}

void	ft_builtins(t_all *head, char **env)
{
	if (ft_strncmp(head->cmds[0], "exit", 10) == 0)
		ft_exit(head->cmds);
	else if (ft_strncmp(head->cmds[0], "pwd", 10) == 0)
		ft_pwd();
	else if (ft_strncmp(head->cmds[0], "echo", 10) == 0)
		ft_echo(head->cmds);
	else if (ft_strncmp(head->cmds[0], "cd", 10) == 0)
		ft_cd(head->cmds, env);
}
