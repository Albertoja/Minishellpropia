/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:53 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/18 18:28:23 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_matrix(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all->matrix_input[i])
	{
		j = 0;
		while (all->matrix_input[i][j])
		{
			write(1, &all->matrix_input[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
