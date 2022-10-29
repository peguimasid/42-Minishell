NAME=minishell

SRCS	= src/main.c		\
				src/minishell.c 	\
				src/utils.c 	\
				src/common.c 	\
				src/parse.c 	\
				src/exec/execute.c 	\
				src/exec/find_path.c 	\
				src/exec/handle_prompt.c 	\
				src/exec/run_cmd.c 	\
				src/builtins/utils.c 	\
				src/builtins/cd.c 	\
				src/builtins/env.c 	\
				src/env/init.c 	\
				src/env/write.c 	\
				src/env/read.c 	\

LIBFT = lib/libft/libft.a

OBJ	= $(SRCS:.c=.o)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	make -s -C lib/libft
	cc $(OBJ) -lreadline -o $(NAME) $(LIBFT)

all: $(NAME)

clean:
	make clean -s -C lib/libft
	rm -f $(OBJ)

fclean: clean
	make fclean -s -C lib/libft
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re norminette

norminette:
	-norminette ./include/*.h
	-norminette ./src/*.c

norm: norminette

valgrind: all
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --error-limit=no --gen-suppressions=all --log-file=lib.log ./$(NAME)
