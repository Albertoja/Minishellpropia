
SRCS	= main.c wait_input.c check_str.c error.c split_pipe.c print_matrix.c ft_make_lst.c create_history.c get_next_line.c search_files.c search_redirection.c #utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= minishell

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT = libft/libft.a

PATHLIB = libft/

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${LIBFT} ${OBJS}
				${CC} ${CFLAGS} ${LIBFT} ${OBJS} -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include -o ${NAME}

${LIBFT}:
			@make -C ${PATHLIB}

all:		${NAME}

clean:
				@make clean -C ${PATHLIB}
				${RM} ${OBJS} ${OBJB}

fclean: 	clean
				@make fclean -C ${PATHLIB}
				${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
