/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:53:55 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/18 20:06:59 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_create_lst(t_all *all)
{
	t_all *head;
	int	cont;
	
	cont = -1;
	while (all->matrix_input[++cont])
	{
		ft_lstadd_back(&head, ft_lstnew(all->matrix_input[cont]));
	}
	cont = 0;
	while (head)
	{
		printf("%p\n", head);
		head = head->next;
		cont++;
	}
	ft_lstclear(&head);
}
