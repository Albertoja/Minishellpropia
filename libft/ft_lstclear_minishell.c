#include "libft.h"

void	ft_lstclear_minishell(t_all **lst)
{
	t_all	*temp;

	if (!*lst)
		return ;
	temp = *lst;
	*lst = NULL;
	while (temp)
	{
		if (temp->cmds)
			ft_free_matrix(temp->cmds);
		if (temp->files)
			ft_free_matrix(temp->files);
		if (temp->dir)
			free(temp->dir);
		free(temp);
		temp = temp->next;
	}
}
