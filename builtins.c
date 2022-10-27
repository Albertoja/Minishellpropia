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

		if (str[1][0] == '-' || str[1][cont] < '0' || str[1][cont] > '9' || ft_strlen(str[1]) >= 19)
		{
			if (str[1][0] != '-' && str[1][cont] == '-')
			{
				printf("minishell: exit: %s: numeric argument required\n", str[1]);
				exit(255);
			}
		}
		cont++;
	}
	if (str[1][0] == '-' && ft_strncmp("-9223372036854775808", str[1], 21) < 0)
		printf("minishell: exit: %s: numeric argument required\n", str[1]);
	else if (str[1][0] != '-' && ft_strncmp("9223372036854775807", str[1], 21) < 0)
		printf("minishell: exit: %s: numeric argument required\n", str[1]);
	env = ft_atoi(str[1]);
	exit(env);
}

void	ft_builtins(t_all *head)
{
	if (ft_strncmp(head->cmds[0], "exit", 10) == 0)
		ft_exit(head->cmds);
}
