/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:31:05 by aespinos          #+#    #+#             */
/*   Updated: 2023/03/08 20:59:56 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

char	*get_pwd(void)
{
	char	*ret;

	ret = malloc(sizeof(char) * PATH_MAX);
	if (getcwd(ret, PATH_MAX) == NULL)
	{
		printf("Error es: %s\n", strerror(errno));
		free(ret);
		return (NULL);
	}
	return (ret);
	/*int		len;

	len = 1;
	ret = NULL;
	while (1)
	{
		ret = malloc(sizeof(char) * len);
		if (getcwd(ret, len) == NULL)
			free(ret);
		else
			break ;
		len++;
	}*/
}
