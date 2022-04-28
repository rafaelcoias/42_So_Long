# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 12:10:14 by rade-sar          #+#    #+#              #
#    Updated: 2022/04/26 11:48:17 by rade-sar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## 		   NAMES 		##########

NAME = libft.a

########## 		  SOURCES 		##########

SRC = 	./ft_isalpha.c	\
		./ft_isdigit.c	\
		./ft_strcmp.c	\
		./ft_isascii.c	\
		./ft_isalnum.c	\
		./ft_isprint.c	\
		./ft_atoi.c 	\
		./ft_memcpy.c 	\
		./ft_bzero.c 	\
		./ft_strlen.c 	\
		./ft_memset.c 	\
		./ft_strchr.c 	\
		./ft_strlcat.c 	\
		./ft_strlcpy.c 	\
		./ft_tolower.c 	\
		./ft_toupper.c 	\
		./ft_strncmp.c 	\
		./ft_strnstr.c 	\
		./ft_strrchr.c 	\
		./ft_memcmp.c 	\
		./ft_memchr.c 	\
		./ft_memmove.c 	\
		./ft_calloc.c 	\
		./ft_strdup.c 	\
		./ft_substr.c 	\
		./ft_strjoin.c 	\
		./ft_strtrim.c 	\
		./ft_split.c 	\
		./ft_itoa.c 	\
		./ft_strmapi.c 	\
		./ft_striteri.c \
		./ft_putchar_fd.c	\
		./ft_putstr_fd.c 	\
		./ft_putendl_fd.c	\
		./ft_putnbr_fd.c	\
		./ft_atol.c 	\
		./ft_lstnew.c 	\
		./ft_lstadd_front.c	\
		./ft_lstadd_front.c \
		./ft_lstsize.c 	\
		./ft_lstlast.c 	\
		./ft_lstadd_back.c	\
		./ft_lstdelone.c 	\
		./ft_lstclear.c \
		./ft_lstiter.c 	\
		./ft_lstmap.c	\
		./get_next_line/get_next_line.c			\
		./get_next_line/get_next_line_utils.c	\
		./ft_print_f/ft_printf.c				\
		./ft_print_f/ft_putchar.c				\
		./ft_print_f/ft_putstr.c				\
		./ft_print_f/ft_putnbr.c				\
		./ft_print_f/ft_puthexa.c				\
		./ft_print_f/ft_putvoid.c				\

########## 		  INCLUDES 		##########

HEAD = ./include

########## 		COMPILATION 	##########

OBJ = ${SRC:.c=.o}

CC = gcc

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEAD}

########## 		   FLAGS 		##########

CFLAGS = -Wall -Wextra -Werror

########## 		   COLORS 		##########

GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET       =   \033[0m

########## 		  COMMANDS		##########

RM = rm -f

AR = ar rc

RANLIB = ranlib

########## 		  MESSAGES 		##########

NORM_LIBFT_MSG = @echo "\n<========== $(YELLOW)Norm $(NAME)$(RESET) ==========>\n"

########## 		  TARGETS 		##########

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}
	${RANLIB} ${NAME}

########## 		   RULES 		##########

all: ${NAME}

clean: 
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re:	fclean all

norm:
	${NORM_LIBFT_MSG}
	norminette -R CheckForbiddenSourceHeader *.c
	norminette -R CheckDefine *.h

.PHONY: all clean fclean re norm