/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:36:37 by aespinos          #+#    #+#             */
/*   Updated: 2022/12/19 16:35:01 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_files04(char *str, char *str_aux, int *cont)
{
	while (str[cont[0]] && str[cont[0]] != ' ')
	{
		if (str[cont[0]] == '<' || str[cont[0]] == '>')
			str_aux[cont[1]] = ' ';
		else
			str_aux[cont[1]] = str[cont[0]];
		cont[0]++;
		cont[1]++;
	}
	return (str_aux);
}

char	*search_files03(char *str, char *str_aux, int *cont)
{
	str_aux[cont[1]] = str[cont[0]];
	cont[0]++;
	cont[1]++;
	while (str[cont[0]] != '"')
	{
		str_aux[cont[1]] = str[cont[0]];
		cont[0]++;
		cont[1]++;
	}
	str_aux[cont[1]] = str[cont[0]];
	cont[0]++;
	cont[1]++;
	return (str_aux);
}

char	*search_files05(char *str, char *str_aux, int *cont)
{
	if (str[cont[0]] == '<' || str[cont[0]] == '>')
	{
		while (str[cont[0]] == '<' || str[cont[0]] == '>')
		{
			str_aux[cont[1]++] = ' ';
			cont[0]++;
		}
		if (str[cont[0]] == ' ')
			cont[0]++;
		if (str[cont[0]] == '"')
			str_aux = search_files03(str, str_aux, cont);
		else
			str_aux = search_files04(str, str_aux, cont);
	}
	else
		cont[0]++;
	return (str_aux);
}

char	*search_files02(char *str, int len)
{
	int		cont[2];
	char	*str_aux;

	cont[0] = 0;
	cont[1] = 0;
	str_aux = malloc(sizeof(char) * (len + 1));
	while (str[cont[0]])
		str_aux = search_files05(str, str_aux, cont);
	str_aux[cont[1]] = '\0';
	return (str_aux);
}

char	**search_files(char *str)
{
	char	**ret;
	char	*str_aux;
	int		cont;
	int		cont2;

	cont = 0;
	cont2 = search_files01(str);
	str_aux = search_files02(str, cont2);
	ret = ft_split_pipe(str_aux, ' ');
	free(str_aux);
	return (ret);
}
