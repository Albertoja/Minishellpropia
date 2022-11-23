/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:25:27 by aespinos          #+#    #+#             */
/*   Updated: 2022/11/23 19:58:31 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**copy_str_matrix(char **env, char *str, int a)
{
	int		i;
	char	**new_env;

	i = -1;
	new_env = malloc(sizeof(char *) * (count_str(env) + 2));
	while (env[++i])
	{
		if (i == a && a != -1)
			new_env[i] = ft_strdup(str);
		else
			new_env[i] = ft_strdup(env[i]);
	}
	if (a == -1)
		new_env[i] = ft_strdup(str);
	new_env[++i] = NULL;
	return (new_env);
}

char	*search_line_env(char *str, char **env)
{
	char	*ret;
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str)) == 0)
		{
			ret = malloc(sizeof(char) * (ft_strlen(*env) - ft_strlen(str)) + 1);
			while (env[i][j])
			{
				while (env[i][j] != '=')
					j++;
				j++;
				while (env[i][j])
				{
					ret[a] = env[i][j];
					a++;
					j++;
				}
			}
			return (ret);
		}
		i++;
	}
	return (NULL);
}

char	*elim_dollar_putequal(char *str)
{
	char	*ret;
	int		a;
	
	a = 0;
	ret = malloc(sizeof(char) * (ft_strlen(str)) + 1);
	str++;
	while (*str)
	{
		ret[a] = *str;
		a++;
		str++;
	}
	ret[a] = '=';
	a++;
	ret[a] = '\0';
	return (ret);
}

char	**ft_dollar_sust(char **env, char **mat, int pos)
{
	char	**ret;
	char	*straux;
	char	*sust;

	straux = elim_dollar_putequal(mat[pos]);
	sust = search_line_env(straux, env);
	ret = copy_str_matrix(mat, sust, pos);
	
	return (ret);
}

char	**ft_dollar(char **mat, char **env)
{
	char	**ret;
	int		i;

	ret = mat;
	i = 0;
	while (mat[i])
	{
		if (mat[i][0] == '$')
			ret = ft_dollar_sust(env, ret, i);
		i++;
	}
	return(ret);
}
