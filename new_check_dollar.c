/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_check_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:45:41 by aespinos          #+#    #+#             */
/*   Updated: 2023/01/17 20:03:56 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

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
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str && *str)
		str++;
	while (str && *str && *str != ' ' && *str != '"')
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
	int		cont;
	char	*ret;
	int		cont_aux;
	char	*dollar;
	char	a;

	a = ' ';
	cont = 0;
	ret = NULL;
	while (str[cont])
	{
		if (str[cont] == '"' && a == '"')
			a = ' ';
		else if (str[cont] == '"')
			a = '"';
		if (str[cont] == '$')
		{
			if(!ret)
				ret = ft_strdup(ft_str_copy_num(str, cont));
			else
				ret = ft_strjoin(ret, ft_str_copy_num(str, cont));
			printf("staaaaaaaar = %s\n", ret);
			cont_aux = cont;
			while ((cont_aux--) && *str)
				str++;
			printf("str = %s\n", str);
			cont_aux = 0;
			while(str[cont_aux] != a && str[cont_aux])
				cont_aux++;
			dollar = ft_str_copy_num(str, cont_aux);
			printf("DOLLAR = %s\n", dollar);
			dollar = elim_dollar_putequal_str(dollar);
			dollar = search_line_env(dollar, env);
			ret = ft_strjoin(ret, dollar);
			while (cont_aux-- && *str)
				str++;
			cont = 0;
			free(dollar);
			//printf("ret = %s\n", dollar);
		}
		cont++;
	}
	if(str)
		ret = ft_strjoin(ret, str);
	return(ret);
}
