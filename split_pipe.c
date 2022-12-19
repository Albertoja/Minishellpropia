/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:57 by aespinos          #+#    #+#             */
/*   Updated: 2022/12/19 16:37:37 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count(char const *s, char c, int i)
{
	int		a;
	char	aux;

	a = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		if (s[i] == 34 || s[i] == 39)
		{
			aux = s[i];
			i++;
			a++;
			while (s[i] != aux)
			{
				i++;
				a++;
			}
		}
		a++;
		i++;
	}
	return (a);
}

int	ft_countwords(char const *s, char c)
{
	int		i;
	int		cont;
	char	aux;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
				i++;
		if (s[i] == '\0')
			break ;
		while (s[i] && s[i] != c)
		{
			if (s[i] == 34 || s[i] == 39)
			{
				aux = s[i++];
				while (s[i] && s[i] != aux)
					i++;
			}
			i++;
		}
		cont++;
	}
	return (cont);
}

char	**ft_splitaux2(char **str, const char *s, char c, int *cont)
{
	char	aux;

	cont[1] = 0;
	while (s[cont[2]] != '\0' && s[cont[2]] != c)
	{
		if (s[cont[2]] == 34 || s[cont[2]] == 39)
		{
			aux = s[cont[2]];
			str[cont[0]][cont[1]++] = s[(cont[2])++];
			while (s[cont[2]] != aux)
				str[cont[0]][cont[1]++] = s[(cont[2])++];
		}
		str[cont[0]][cont[1]++] = s[(cont[2])++];
	}
	str[cont[0]][cont[1]] = '\0';
	while (s[cont[2]] == c && s[cont[2]])
		(cont[2])++;
	return (str);
}

char	**ft_splitaux(char **str, const char *s, char c, int a)
{
	int		pal;
	int		cont[3];

	cont[0] = 0;
	cont[1] = 0;
	cont[2] = a;
	pal = ft_countwords(s, c);
	while (pal--)
	{
		str[cont[0]] = (char *)malloc(sizeof(char) * (ft_count(s, c, a) + 1));
		if (!str[cont[0]])
		{
			ft_free_matrix(str);
			return (NULL);
		}
		str = ft_splitaux2(str, s, c, cont);
		cont[0]++;
	}
	str[cont[0]] = NULL;
	return (str);
}

char	**ft_split_pipe(char const *s, char c)
{
	int		a;
	char	**str;

	a = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[a] == c)
		(a)++;
	return (ft_splitaux(str, s, c, a));
}
