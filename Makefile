NAME=minishell

SRCS = $(shell find src -name '*.c')

LIBFT = lib/libft/libft.a

OBJ	= $(SRCS:.c=.o)

CPPFLAGS = -I ~/.brew/Cellar/readline/8.2.1/include
LDFLAGS = -L ~/.brew/Cellar/readline/8.2.1/lib



$(NAME): $(OBJ)
	make bonus -s -C lib/libft
	cc -g -Wall -Wextra -Werror $(SRCS) -o $(NAME) $(LIBFT) -lreadline $(CPPFLAGS) $(LDFLAGS)

all: $(NAME)

clean:
	make clean -s -C lib/libft
	rm -f $(OBJ)

fclean: clean
	make fclean -s -C lib/libft
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re norminette

valgrind: all
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --error-limit=no --gen-suppressions=all --track-origins=yes  --log-file=lib.log ./minishell
