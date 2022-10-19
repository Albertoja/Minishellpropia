/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aespinos <aespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:27:12 by aespinos          #+#    #+#             */
/*   Updated: 2022/10/19 19:28:15 by aespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# define RESET				"\x1b[0m"
# define WHITE				"\x1b[1m"
# define GRAY				"\x1b[2m"
# define BLACK				"\x1b[30m"
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE				"\x1b[34m"
# define PURPLE				"\x1b[35m"
# define CYAN				"\x1b[36m"

// typedef struct s_list
// {
// 	char			*content;
// 	struct s_list	*next;
// }	t_list;

// typedef struct s_list
// {
// 	int				content;
// 	struct s_list	*next;
// }					t_list;

// typedef struct s_all {
// 	char	**matrix_input;
// 	t_list	**commands;
// }	t_all;


typedef struct s_all {
	char	**matrix_input;
	char			**cmds;
	char			**files;
	char			*dir;
	struct s_all	*next;
}				t_all;

void	ft_wait_for_input(void);
void	check_str(char *str);
void	ft_error(char *str);
char	**ft_split_pipe(char const *s, char c);
void	ft_print_matrix(char **matrix);
void	ft_create_lst(char **matrix);
void	ft_lstadd_back(t_all **lst, t_all *new);
void	ft_free_matrix(char **matrix);
t_all	*ft_lstnew(void *content);
void	ft_lstclear(t_all **lst);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
#endif
