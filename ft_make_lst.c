/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:53:55 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/19 19:54:53 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_redirection(char *straux)
{
	int	cont;

	cont = 0;
	while(straux[cont])
	{
		if (straux[cont] == '<')
		{
			if (!straux[cont + 1])
				ft_error("bad redirection");
			else
			{
				cont++;
				if (straux[cont] == '<')
				{
					if (!straux[cont + 1])
						ft_error("bad redirection");
					else
						return (3);
				}
				else
					return (1);
			}
		}
		else if (straux[cont] == '>')
		{
			if (!straux[cont + 1])
				ft_error("bad redirection");
			else
			{
				cont++;
				if (straux[cont] == '>')
				{
					if (!straux[cont + 1])
						ft_error("bad redirection");
					else
						return (4);
				}
				else
					return (2);
			}
		}
		cont++;
	}
	return (0);
}
char	*search_cmds(char *str)
{
	char *straux;
	int len;
	int lenaux;
	
	len = 0;
	lenaux = 0;
	while(str[len] && str[len] != '<' && str[len] != '>')
	{
		len++;
	}
	straux = malloc(sizeof(char) * (len + 1));
	while(lenaux < len)
	{
		straux[lenaux] = str[lenaux];
		lenaux++;
	}
	straux[lenaux] = '\0';
	printf("comandos:%s\n", straux);
	return(straux);
}

void	ft_create_lst(char **matrix)
{
	t_all *head;
	int	cont;
	char *straux;
	int	red;
	cont = 0;
	head = malloc(sizeof(t_all));
	while(matrix[cont])
	{
		straux = search_cmds(matrix[cont]);
		red = search_redirection(matrix[cont]);
		head->cmds = ft_split_pipe(straux, ' ');
		printf("redireccion:%i\n", red);
		ft_print_matrix(head->cmds);
		cont++;
		head->next = head;
	}
	head = NULL;
	ft_free_matrix(matrix);
	ft_lstclear(&head);
}

