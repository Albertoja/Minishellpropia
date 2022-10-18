/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:50 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/18 20:10:36 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void    leaks(void)
// {
//     system("leaks minishell");
// }


int	main(void)
{
	//atexit(leaks);
	ft_wait_for_input();
}
