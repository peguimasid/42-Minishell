NAME=minishell

MAIN_DIR = src/
MAIN_FILES = main.c error.c minishell.c signal.c free.c
MAIN_SRCS = $(addprefix $(MAIN_DIR), $(MAIN_FILES))

ENV_UTILS_DIR = src/utils/env/
ENV_UTILS_FILES = get_env.c set_env.c
ENV_UTILS_SRCS = $(addprefix $(ENV_UTILS_DIR), $(ENV_UTILS_FILES))

MATRIX_UTILS_DIR = src/utils/matrix/
MATRIX_UTILS_FILES = matrix_dup.c matrix_free.c matrix_len.c matrix_push.c matrix_replace.c
MATRIX_UTILS_SRCS = $(addprefix $(MATRIX_UTILS_DIR), $(MATRIX_UTILS_FILES))

SRCS	=	$(MAIN_SRCS)	\
				$(ENV_UTILS_SRCS)	\
				$(MATRIX_UTILS_SRCS)	\

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
