/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endquotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:52:36 by aespinos          #+#    #+#             */
/*   Updated: 2022/12/14 17:54:58 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

char	*search_first_cmd(char *input)
{
	int		a;
	char	*cmd;

	a = 0;
	while (input[a] != ' ')
		a++;
	cmd = malloc(sizeof(char) * (a + 1));
	a = 0;
	while (input[a] != ' ')
	{
		cmd[a] = input[a];
		a++;
	}
	return (cmd);
}

char	*sust_a(char *input, char a)
{
	char	*aux;
	int		i;
	int		j;

	aux = malloc(sizeof(char) * (ft_strlen(input) + 1));
	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == a)
			i++;
		else
		{
			aux[j] = input[i];
			i++;
			j++;
		}
	}
	aux[j] = a;
	j++;
	aux[j] = '\0';
	return (aux);
}

char	*search_a(char	*input, char a)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == a)
		{
			input = sust_a(input, a);
			return (input);
		}
		i++;
	}
	return (input);
}

char	*ft_endquotes(char *oldinput, char a)
{
	char	*input;
	int		i;
	char	*firstcmd;

	firstcmd = search_first_cmd(oldinput);
	i = 0;
	while (1)
	{
		input = readline(YELLOW">"RESET);
		if (input && *input)
		{
			input = search_a(input, a);
			oldinput = ft_strjoin(oldinput, "\n");
			oldinput = ft_strjoin(oldinput, input);
			while (input[i])
				i++;
			if (input[i - 1] == a)
				return (oldinput);
			else
				i = 0;
		}
	}
	return (oldinput);
}
