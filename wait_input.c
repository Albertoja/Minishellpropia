/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:59 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/19 18:17:17 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait_for_input(void)
{
	char	**matrix;
	char	*input;

	while (1)
	{
		input = readline(YELLOW"Minishell $>"RESET);
		if (!input)
			exit(1);
		ft_create_history(input);
		check_str(input);
		matrix = ft_split_pipe(input, '|');
		if (!matrix)
			exit(13);
		//ft_print_matrix(matrix);
		free(input);
		ft_create_lst(matrix);
	}
}
