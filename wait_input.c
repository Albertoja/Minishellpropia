/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:59 by aespinos          #+#    #+#             */
/*   Updated: 2023/01/10 18:43:17 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait_for_input(char **env, int status)
{
	t_all	*head;
	char	**matrix;
	char	*input;

	status = 0;
	while (1)
	{
		input = readline(RED"M"BLUE"i"GREEN"n"GRAY"i"PURPLE"s"CYAN"h"WHITE"e"YELLOW"ll"RESET" $>");
		if (input && *input)
		{
			ft_create_history(input);
			input = check_str(input);
			matrix = ft_split_pipe(input, '|');
			if (!matrix)
				exit(0);
			head = ft_create_lst(matrix, env);
			env = ft_builtins(head, env);
			ft_lstclear_minishell(&head);
			//exit(0);
		}
		free(input);
	}
}
