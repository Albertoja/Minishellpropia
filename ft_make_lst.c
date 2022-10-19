/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:53:55 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/19 17:51:01 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_create_lst(char **matrix)
{
	t_all *head;
	t_all *temp;
	int	cont;
	
	cont = 0;
	head = ft_calloc(sizeof(t_all), 1);
	temp = head;
	while(matrix[cont])
	{
		head->cmds = ft_split_pipe(matrix[cont], ' ');
		ft_print_matrix(head->cmds);
		cont++;
		head->next = head;
	}
	ft_lstclear(&head);
}

