/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:53:55 by aespinos          #+#    #+#             */
/*   Updated: 2023/03/08 19:20:41 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redcomp(char *red)
{
	int	cont;

	cont = -1;
	while (red[++cont])
	{
		if (red[cont] == '0')
			return (0);
	}
	return (1);
}

t_all	*ft_basic_parse(char *str, t_all *head)
{
	head->dir = search_redirection(str);
	head->cmds = search_cmds(str);
	head->files = search_files(str);
	head->files = ft_clean_quotes(head->files);
	head->cmds = ft_clean_quotes(head->cmds);
	return (head);
}

t_all	*ft_parse(char **matrix, int *cont)
{
	t_all	*head;

	head = ft_calloc(sizeof(t_all), 1);
	if (matrix[++(*cont)])
		head = ft_basic_parse(matrix[*cont], head);
	return (head);
}

t_all	*ft_create_lst(char **matrix)
{
	t_all	*head;
	int		cont;

	cont = -1;
	head = ft_parse(matrix, &cont);
	while (matrix[cont])
		ft_lstadd_back(&head, ft_parse(matrix, &cont));
	ft_free_matrix(matrix);
	return (head);
}
