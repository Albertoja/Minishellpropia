#include "minishell.h"

void	ft_exit(char **str)
{
	int	env;
	int	cont;

	cont = 0;
	if (!str[1])
		exit(0);
	while (str[1][cont])
	{
		if (str[1][cont] < '0' || str[1][cont] > '9')
		{
			printf("minishell: exit: %s: numeric argument required\n", str[1]);
			exit(255);
		}
		cont++;
	}
	env = ft_atoi(str[1]);
	exit(env);
}

void	ft_builtins(t_all *head)
{
	if (ft_strncmp(head->cmds[0], "exit", 10) == 0)
		ft_exit(head->cmds);
}
