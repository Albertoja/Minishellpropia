#include "minishell.h"
int	ft_check_export(char *str)
{
	if (!ft_strchr(str, '='))
		return (0);
	if (ft_isalpha(*str) == 0 && *str != '_')
		return (0);
	while (*str != '=')
	{
		if (*str != '_' && ft_isalnum(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
static char	**copy_str_matrix(char **env, char *str)
{
	int		i;
	char	**new_env;

	i = -1;
	new_env = malloc(sizeof(char *) * (count_str(env) + 2));
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = ft_strdup(str);
	new_env[++i] = NULL;
	ft_free_matrix(env);
	return (new_env);
}

char	**ft_export(char **cmds, char **env)
{
	int	cont;
	int	cont2;

	cont2 = 1;
	cont = 0;
	if (!cmds[1] || !cmds || !*cmds)
	{
		while(env[cont])
		{
			printf("declare -x %s\n", env[cont]);
			cont++;
		}
		return (env);
	}
	while(cmds[cont2])
	{
		if (ft_check_export(cmds[cont2]) != 1)
		{
			printf("export: `%s': not a valid identifier\n", cmds[cont2]);
			exit(0);
		}
		env = copy_str_matrix(env, cmds[cont2]);
		ft_print_matrix(env);
		env = copy_str_matrix(env, cmds[cont2]);
		cont2++;
	}
	return (env);
}
