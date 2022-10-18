/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:59 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/18 20:13:49 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait_for_input(void)
{
	char	*input;
	t_all	*all;

	all = NULL;
	while (1)
	{
		input = readline(YELLOW"Minishell $>"RESET);
		if (!input)
			exit(1);
		check_str(input);
		all->matrix_input = ft_split_pipe(input, '|');
		if (!all->matrix_input)
			exit(13);
		free(input);
		exit(0);
		ft_create_lst(all);
		ft_free_matrix(all->matrix_input);
		
		exit(0);
	}
}
