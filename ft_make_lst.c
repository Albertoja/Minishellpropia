/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:53:55 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/20 17:32:13 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_redirection(char *straux)
{
	int	cont;
	char *ret;
	
	cont = 0;
	ret = NULL;
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
					{
						if (!ret)
							ret = ft_strdup("3");
						else
							ret = ft_strjoin(ret, "3");
					}
				}
				else
				{
					if (!ret)
						ret = ft_strdup("1");
					else
						ret = ft_strjoin(ret, "1");
				}
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
					{
						if (!ret)
							ret = ft_strdup("4");
						else
							ret = ft_strjoin(ret, "4");
					}
				}
				else
				{
					if (!ret)
						ret = ft_strdup("2");
					else
						ret = ft_strjoin(ret, "2");
				}
			}
		}
		cont++;
	}
	return (ret);
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
	int	cont2;
	cont = 0;
	cont2 = 0;
	head = malloc(sizeof(t_all));
	while(matrix[cont])
	{
		head->dir = search_redirection(matrix[cont]);
		printf("redireccion:%s\n", head->dir);
		head->cmds = ft_split_pipe(search_cmds(matrix[cont]), ' ');
		cont++;
		head->next = head;
	}
	head = NULL;
	ft_free_matrix(matrix);
	ft_lstclear(&head);
}
