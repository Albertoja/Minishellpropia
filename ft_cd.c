/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:28:29 by aespinos          #+#    #+#             */
/*   Updated: 2023/03/16 17:53:41 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

char	*back_one_dir(char *path)
{
	int		len;
	char	*new_dir;

	if (ft_strncmp(path, "/", 5) == 0)
		return (path);
	len = ft_strlen(path);
	while (path[len] != '/')
		len--;
	new_dir = ft_substr(path, 0, len);
	return (new_dir);
}

char	*check_dir(char **args, char *path, int *status)
{
	char	*new_dir;
	char	*aux;
	static	int sw;

	if (args[1] && args[1][0] == '/')
		return (args[1]);
	path = ft_strjoinm(path, "/");
	new_dir = ft_strjoinm(path, args[1]);
	if (new_dir[ft_strlen(new_dir) - 1] == '/')
	{
		aux = ft_substr(new_dir, 0, ft_strlen(new_dir) - 1);
		free(new_dir);
		new_dir = aux;
	}
	free(path);
	if (access(new_dir, F_OK) == 0)
		return (new_dir);
	else
	{
		if(sw == 1)
		{
			sw = 0;
			new_dir = back_one_dir(new_dir);
			new_dir = back_one_dir(new_dir);
			new_dir = back_one_dir(new_dir);
			return(new_dir);
		}
		*status = ft_errorcd(args[1]);
		if(ft_strncmp(args[1], "..", 2) == 0)
		{
			sw = 1;
			return(new_dir);
		}
		free(new_dir);
	}
	sw = 0;
	//free(new_dir);
	return (NULL);
}

void	replace_pwd_oldpwd(char *new_dir, char *path, char **env, char **args)
{
	int		i;
	char	*aux;

	i = -1;
	if (chdir(new_dir) != 0 && (ft_strncmp(args[1], "..", 2) != 0))
	{
		//free(aux);
		return ;
	}
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
		{
			aux = env[i];
			if (access(new_dir, F_OK) != 0)
			{
				env[i] = ft_strjoinm("PWD=", new_dir);
			}
			else
				env[i] = ft_strjoinm("PWD=", get_pwd());
			free(aux);
		}
	}
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "OLDPWD=", 4) == 0)
		{
			aux = env[i];
			env[i] = ft_strjoinm("OLDPWD=", path);
			free(aux);
		}
	}
}

char	*get_home(char **env, int *status, char *home)
{
	char	*new_dir;

	if (ft_strncmp(home, "HOME=", 5) == 0)
	{
		new_dir = ft_substr(home, 5, UINT_MAX);
		return (new_dir);
	}
	else
	{
		while (*env)
		{
			if (ft_strncmp(*env, "HOME=", 5) == 0)
			{
				new_dir = ft_substr(*env, 5, UINT_MAX);
				return (new_dir);
			}
			env++;
		}
		ft_putstr_fd("minishell: cd : HOME not set\n", 1);
		*status = 1;
		return (NULL);
	}
}

char	**ft_cd(char **args, char **env, int *status, char *home)
{
	char	*path;
	char	*new_dir;

	if (!env)
		return (NULL);
	path = get_pwd();
	if (!args[1] || ft_strncmp(args[1], "~", 5) == 0)
		new_dir = get_home(env, status, home);
	else if (ft_strncmp(args[1], "-", 5) == 0)
		new_dir = get_oldpwd(env);
	else
		new_dir = check_dir(args, path, status);
	if (new_dir)
		replace_pwd_oldpwd(new_dir, path, env, args);
	free(path);
	return (env);
}
