/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:59 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/19 16:33:28 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait_for_input(void)
{
	char	**matrix;
	char	*input;
	t_all	*all;

	all = NULL;
	while (1)
	{
		input = readline(YELLOW"Minishell $>"RESET);
		if (!input)
			exit(1);
		check_str(input);
		matrix = ft_split_pipe(input, '|');
		if (!matrix)
			exit(13);
		//ft_print_matrix(matrix);
		free(input);
		ft_create_lst(matrix);
		ft_free_matrix(matrix);
		
		exit(0);
	}
}
