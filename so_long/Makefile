NAME = so_long

SRC = ./src/main.c

HEAD = ./include

MAKE_LIBFT = cd ./include/libft && make all

LIBFT_PATH = ./include/libft

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

# COLORS #
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET       =   \033[0m

${NAME}: ${OBJ} 
	${MAKE_LIBFT} -s
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft
	@echo "\n ======= $(GREEN)so_long created$(RESET) ======= \n"

# RULES #

all: ${NAME} 

clean:
	@cd ./include/libft && make clean -s
	${RM} ${OBJ}

fclean: clean 
	@cd ./include/libft && make fclean -s
	${RM} ${NAME} ${CHECK}
	@echo "\n ======= $(RED)so_long removed$(RESET) ======= \n"
	

re:	fclean all

norm:
	@echo "\n ======= $(YELLOW)norm libft$(RESET) ======= \n"
	@cd ./include/libft && norminette -R CheckForbiddenSourceHeader *.c && norminette -R CheckDefine *.h
	@echo "\n ======= $(YELLOW)norm so_long$(RESET) =======\n "
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine push_swap.h

.PHONY: all clean fclean re norm