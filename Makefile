NAME		= minishell
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -lreadline
RM			= rm -rf
SRCS		=  src/main.c src/cd_pwd.c src/execute.c src/treatment_chr.c \
				src/all_free.c src/ft_echo_cd.c src/unset.c \
				src/redirected.c src/treament_lst.c src/utils.c \
				src/export.c src/export2.c src/util2.c src/init_execc.c \
				src/redirc.c src/signal.c src/exit.c src/traitement_prompt.c \
				src/redirect.c src/free_all.c src/split_pipe.c src/check_fd.c \
				src/util3.c

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(LIBFT) $(FLAGS) -o $(NAME)
		@echo "✅ ✅ ✅ \033[3m\e[1;32mAll is done\e[0;m\033[0m✅ ✅ ✅ "

all :	$(NAME)

$(LIBFT):
		@make -C libft

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		@make clean -C libft

fclean: clean
		$(RM) $(NAME)
		@make fclean -C libft
 
re: fclean all

# valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all ./minishell

