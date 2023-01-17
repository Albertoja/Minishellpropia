/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dollar_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:06:34 by aespinos          #+#    #+#             */
/*   Updated: 2023/01/17 18:47:12 by aespinos         ###   ########.fr       */
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

int	ft_strlen_space(char *str)
{
	int	ret;

	if (!str || !*str)
		return (0);
	ret = 0;
	while (str[ret] && str[ret] != ' ')
		ret++;
	return (ret);
}

char	*elim_dollar_putequal_str(char *str)
{
	char	*ret;
	int		a;

	a = 0;
	while (*str && *str != '$')
		str++;
	ret = malloc(sizeof(char) * (ft_strlen_space(str) + 1));
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

char	*dollar_copy_str_02(char *str, int len)
{
	char		*ret;
	int			lenaux;
	static int	cont;

	while (str[len] != ' ' && str[len])
		len++;
	lenaux = len;
	while (str[len++])
		cont++;
	ret = malloc(sizeof(char) * (cont) + 1);
	cont = 0;
	while (str[lenaux])
		ret[cont++] = str[lenaux++];
	if (!*ret)
	{
		free(ret);
		ret = malloc(sizeof(char) * 2);
		ret[0] = '"';
		ret[1] = '\0';
		return (ret);
	}
	ret[cont] = '\0';
	return (ret);
}

char	*dollar_copy_str_01(char *str, int len)
{
	char	*ret;
	int		cont;

	cont = 0;
	ret = malloc(sizeof(char) * (len) + 1);
	while (*str && cont < len)
	{
		ret[cont] = *str;
		cont++;
		str++;
	}
	ret[cont] = '\0';
	return (ret);
}

// char	*ft_dollar_sust_str(char *str, char **env)
// {
// 	char	*straux1;
// 	char	*var;
// 	char	*ret;
// 	int		cont;

// 	cont = 0;
// 	straux1 = str;
// 	while (str[cont++])
// 	{
// 		if (str[cont] == '$')
// 		{
// 			straux1 = dollar_copy_str_01(str, cont);
// 			var = elim_dollar_putequal_str(str);
// 			var = search_line_env(var, env);
// 			straux1 = ft_strjoin(straux1, var);
// 			ret = dollar_copy_str_02(str, cont);
// 			straux1 = ft_strjoin(straux1, ret);
// 			free(ret);
// 			free(str);
// 			free(var);
// 			cont = 0;
// 			str = straux1;
// 		}
// 	}
// 	return (straux1);
// }
