/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_check_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:45:41 by aespinos          #+#    #+#             */
/*   Updated: 2023/01/19 18:53:39 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	ft_strlen_var(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret] && str[ret] != ' ' && str[ret] != '"' && str[ret] != '\'')
		ret++;
	return (ret);
}

char	*ft_strjoin_n(char *str1, char *str2, int n)
{
	int		cont;
	char	*ret;
	char	*aux;

	cont = 0;
	aux = malloc(sizeof(char) * (n + 1));
	while (n--)
	{
		aux[cont] = str2[cont];
		cont++;
	}
	aux[cont] = '\0';
	if (!str1)
		return (aux);
	ret = ft_strjoin(str1, aux);
	free (aux);
	return (ret);
}

char	*search_line_env2(char *ret, char **env, int i)
{
	int	j;
	int	a;

	j = 0;
	a = 0;
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
	ret[a] = '\0';
	return (ret);
}

char	*search_line_env(char *str, char **env)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str)) == 0)
		{
			len = ft_strlen(env[i]) - ft_strlen(str);
			ret = malloc(sizeof(char) * (len + 1));
			ret = search_line_env2(ret, env, i);
			free(str);
			return (ret);
		}
		i++;
	}
	free(str);
	return (ft_strdup(" "));
}

char	*elim_dollar_putequal_str(char *str)
{
	char	*ret;
	int		a;

	a = 0;
	while (*str && *str != '$')
		str++;
	ret = malloc(sizeof(char) * (ft_strlen_var(str) + 1));
	if (str && *str)
		str++;
	while (str && *str && *str != ' ' && *str != '"' && *str != '\'' && *str != '$')
	{
		ret[a] = *str;
		a++;
		str++;
	}
	ret[a] = '=';
	if (ret[a] && ret)
		a++;
	ret[a] = '\0';
	return (ret);
}


char	*ft_dollar_sust_str(char *str, char **env)
{
	char	*ret;
	int		cont;
	char	*var;
	char	*str_aux;

	str_aux = str;
	cont = 0;
	ret = NULL;
	while (str_aux[cont])
	{
		if (str_aux[cont] == '$')
		{
			ret = ft_strjoin_n(ret, str_aux, cont);
			while (*str_aux && *str_aux != '$')
				str_aux++;
			var = elim_dollar_putequal_str(str_aux++);
			var = search_line_env(var, env);
			while (*str_aux && *str_aux != ' ' && *str_aux != '"' && *str_aux != '\'' && *str_aux != '$')
				str_aux++;
			ret = ft_strjoin(ret, var);
			free(var);
			cont = -1;
		}
		cont++;
	}
	ret = ft_strjoin_n(ret, str_aux, cont);
	free(str);
	return(ret);
}
