NAME=minishell

SRCS	= src/main.c		\
			src/builtins/builtin_handler.c \
			src/builtins/pwd.c  src/builtins/cd.c \

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
