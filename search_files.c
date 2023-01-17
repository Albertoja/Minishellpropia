/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_search_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:57:27 by aespinos          #+#    #+#             */
/*   Updated: 2023/01/17 18:20:48 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_noquotes_files(char *str, char a)
{
	str++;
	while (*str != a)
		str++;
	return (str);
}

char	*ft_quotes_files(char *str, char a)
{
	char	*ret;
	int		cont;

	cont = 0;
	while (str[cont] && str[cont] != a)
		cont++;
	ret = malloc(sizeof(char) * (cont + 1));
	cont = 0;
	while (*str && *str != a)
		ret[cont++] = *str++;
	ret[cont] = '\0';
	return (ret);
}

char	*ft_in_files(char *str)
{
	char	*ret;
	int		cont;

	cont = 0;
	while (*str == '<' || *str == '>' || *str == ' ')
		str++;
	if (*str == '"')
		return (ft_quotes_files(++str, '"'));
	else
		return (ft_quotes_files(str, ' '));
	return (ret);
}

char	**search_files(char *str)
{
	char	*str_aux;
	char	**ret;

	str_aux = NULL;
	while (*str)
	{
		if (*str == '<' || *str == '>')
		{
			while (*str == '<' || *str == '>' || *str == ' ')
				str++;
			if (!str_aux)
				str_aux = ft_strdup(ft_in_files(str));
			else
				str_aux = ft_strjoin(str_aux, ft_in_files(str));
			str_aux = ft_strjoin(str_aux, "|");
		}
		if (*str == '"')
			str = ft_noquotes_files(str, '"');
		str++;
	}
	ret = ft_split_pipe(str_aux, '|');
	free (str_aux);
	return (ret);
}
