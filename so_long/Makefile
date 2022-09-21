########## 		   NAMES 		##########

NAME = so_long

BONUS = so_long_bonus

########## 		  SOURCES 		##########

SRC_PATH = ./src/

BONUS_PATH = ./bonus/

SRC =	${SRC_PATH}main.c			\
		${SRC_PATH}check.c 			\
		${SRC_PATH}init_game.c		\
		${SRC_PATH}init_windows.c	\
		${SRC_PATH}init_images.c	\
		${SRC_PATH}error_msg.c		\
		${SRC_PATH}do_game.c		\
		${SRC_PATH}end_game.c		\
		${SRC_PATH}move_player.c	\
		${SRC_PATH}render_images.c	\
		${SRC_PATH}write_in_game.c	\
		${SRC_PATH}init_stats.c		\

SRC_BONUS =	${BONUS_PATH}main.c			\
		${BONUS_PATH}check.c 			\
		${BONUS_PATH}init_game.c		\
		${BONUS_PATH}init_windows.c		\
		${BONUS_PATH}init_images.c		\
		${BONUS_PATH}error_msg.c		\
		${BONUS_PATH}do_game.c			\
		${BONUS_PATH}end_game.c			\
		${BONUS_PATH}move_player.c		\
		${BONUS_PATH}render_images.c	\
		${BONUS_PATH}do_menu_window.c	\
		${BONUS_PATH}init_stats.c		\
		${BONUS_PATH}do_animations.c	\
		${BONUS_PATH}write_in_game.c	\

########## 		  INCLUDES 		##########

HEAD = ./include

MLX	= ./include/mlx/libmlx.a

MLX_PATH = ./include/mlx/

########## 		   LIBFT 		##########

LIBFT = $(LIBFT_PATH)libft.a

LIBFT_PATH = ./include/libft/

########## 		COMPILATION 	##########

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_BONUS:.c=.o}

CC = gcc

########## 		   FLAGS 		##########

CFLAGS = -Wall -Wextra -Werror 

MLX_FLAGS = -lXext -lX11 -lm -lz

########## 		   COLORS 		##########

GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET       =   \033[0m

########## 		  COMMANDS		##########

MAKE_MLX = cd ${MLX_PATH} && make

MAKE_LIBFT = cd ${LIBFT_PATH} && make all

CLEAN_LIBFT = cd ${LIBFT_PATH} && make clean -s

FCLEAN_LIBFT = cd ${LIBFT_PATH} && make fclean -s

RM = rm -f

########## 		  MESSAGES 		##########

CREATE_PROJ_MSG = @echo "\n<========== $(GREEN)$(NAME) created$(RESET) ==========>\n"

CREATE_BONUS_MSG = @echo "\n<========== $(GREEN)$(BONUS) created$(RESET) ==========>\n"

REMOVED_MSG = @echo "\n<========== $(RED)$(NAME) removed$(RESET) ==========>\n"

NORM_PROJ_MSG = @echo "\n<========== $(YELLOW)Norm $(NAME)$(RESET) ==========>\n"

NORM_BONUS_MSG = @echo "\n<========== $(YELLOW)Norm $(BONUS)$(RESET) ==========>\n"

########## 		  TARGETS 		##########

${NAME}: ${OBJ} ${MLX} ${LIBFT}
	$(CC) $(OBJ) $(LIBFT) $(MLX) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)

${BONUS}: ${OBJ_B} ${MLX} ${LIBFT}
	$(CC) $(OBJ_B) $(LIBFT) $(MLX)  $(CFLAGS) $(MLX_FLAGS) -o $(BONUS)

${MLX}: 
		@make -C $(MLX_PATH)

${LIBFT}:
		@make -C $(LIBFT_PATH)

########## 		   RULES 		##########

all: ${NAME}
	@clear
	${CREATE_PROJ_MSG}

bonus: ${BONUS}
	@clear
	${CREATE_BONUS_MSG}

clean:
	@cd $(MLX_PATH) && make clean
	${CLEAN_LIBFT}
	${RM} ${OBJ} ${OBJ_B}

fclean: clean 
	${FCLEAN_LIBFT}
	${RM} ${NAME} ${BONUS}
	${REMOVED_MSG}
	

re:	fclean all

norm:
	@cd ${LIBFT_PATH} && make norm
	${NORM_PROJ_MSG}
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine *.h
	${NORM_BONUS_MSG}
	@cd ./bonus && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine *.h
	@echo "\n"

.PHONY: all bonus clean fclean re norm