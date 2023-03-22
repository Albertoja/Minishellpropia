/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:47:51 by aespinos          #+#    #+#             */
/*   Updated: 2023/03/22 16:54:13 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_read_history(void)
{
	int		fd;
	char	*line;
	char	*aux;

	fd = open("history", O_CREAT | O_RDWR, 0644);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	if (line)
		aux = ft_substr(line, 0, ft_strlen(line) - 1);
	while (line)
	{
		add_history(aux);
		free(line);
		free(aux);
		line = get_next_line(fd);
		if (line)
			aux = ft_substr(line, 0, ft_strlen(line) - 1);
	}
	close (fd);
}

void	ft_create_history(char *input)
{
	int	fd;
	char	*dir;
	char	buff[PATH_MAX + 1];
	dir = getcwd(buff, PATH_MAX + 1);
	dir = ft_strjoinm(dir, "/.history");
	fd = open(dir, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
		return ;
	free(dir);
	add_history(input);
	ft_putstr_fd(input, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
}
