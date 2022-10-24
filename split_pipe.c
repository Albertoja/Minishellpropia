/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:21:57 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/24 19:20:15 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count(char const *s, char c, int i)
{
	int	a;

	a = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		if (s[i] == 34)
		{
			i++;
			a++;
			while (s[i] != 34)
			{
				i++;
				a++;
			}
		}
		if (s[i] == 39)
		{
			i++;
			a++;
			while (s[i] != 39)
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
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
				i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
		{
			if (s[i] == 34)
			{
				i++;
				while (s[i] != 34)
					i++;
			}
			if (s[i] == 39)
			{
				i++;
				while (s[i] != 39)
					i++;
			}
				i++;
		}
		cont++;
	}
	return (cont);
}

static void	**ft_free(char **str, int i)
{
	int	a;

	a = 0;
	while (a < i)
	{
		free (str[a]);
		a++;
	}
	free (str);
	return (0);
}

char	**ft_splitaux(char **str, const char *s, char c, int a)
{
	int	i;
	int	j;
	int	pal;

	pal = ft_countwords(s, c);
	i = 0;
	while (pal--)
	{
		str[i] = (char *)malloc(sizeof(char) * (ft_count(s, c, a) + 1));
		if (!str[i])
		{
			ft_free(str, i);
			return (NULL);
		}
		j = 0;
		while (s[a] != '\0' && s[a] != c)
		{
			if (s[a] == 34)
			{
				str[i][j++] = s[a++];
				while (s[a] != 34)
					str[i][j++] = s[a++];
			}
			else if (s[a] == 39)
			{
				str[i][j++] = s[a++];
				while (s[a] != 39)
					str[i][j++] = s[a++];
			}
			str[i][j++] = s[a++];
		}
		str[i][j] = '\0';
		while (s[a] == c && s[a])
			a++;
		i++;
	}
	str[i] = NULL;
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
		a++;
	return (ft_splitaux(str, s, c, a));
}
