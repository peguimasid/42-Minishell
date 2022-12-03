NAME=minishell

SRCS = $(shell find src lib/gnl -name '*.c')

LIBFT = lib/libft/libft.a

OBJ	= $(SRCS:.c=.o)

CPPFLAGS = -I/opt/homebrew/Cellar/readline/8.2.1/include
LDFLAGS = -L/opt/homebrew/Cellar/readline/8.2.1/lib

$(NAME): $(OBJ)
	make bonus -s -C lib/libft
	cc -Wall -Wextra -Werror $(SRCS) -o $(NAME) $(LIBFT) -lreadline $(CPPFLAGS) $(LDFLAGS)

all: $(NAME)

clean:
	make clean -s -C lib/libft
	rm -f $(OBJ)

fclean: clean
	make fclean -s -C lib/libft
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re norminette
