NAME=minishell

EXEC_DIR = ./src/exec/
EXEC_FILES = execute.c find_path.c handle_prompt.c run_cmd.c free_args.c
EXEC_SRCS = $(addprefix $(EXEC_DIR), $(EXEC_FILES))

BUILTINS_DIR = ./src/builtins/
BUILTINS_FILES = utils.c cd.c
BUILTINS_SRCS = $(addprefix $(BUILTINS_DIR), $(BUILTINS_FILES))

ENV_DIR = ./src/env/
ENV_FILES = init.c write.c read.c free.c export.c
ENV_SRCS = $(addprefix $(ENV_DIR), $(ENV_FILES))

INTERPRETERS_DIR = ./src/interpreters/
INTERPRETERS_FILES = pipe_separator.c
INTERPRETERS_SRCS = $(addprefix $(INTERPRETERS_DIR), $(INTERPRETERS_FILES))

SRCS	=	src/main.c		\
			src/minishell.c 	\
			src/utils.c 	\
			src/common.c 	\
			src/parse.c 	\
			$(EXEC_SRCS)	\
			$(BUILTINS_SRCS)	\
			$(ENV_SRCS)	\
			$(INTERPRETERS_SRCS)

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
