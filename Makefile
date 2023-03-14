# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 19:28:17 by mahender          #+#    #+#              #
#    Updated: 2023/03/13 19:28:22 by mahender         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_PATH = ./source/

SRC = $(addprefix $(SRC_PATH)/, \
push_swap.c utils.c exiting.c push.c reverse.c rotate.c swap.c put_index.c \
sort_three.c sorting.c \
)

OBJS = ${SRC:.c=.o}

LIBFT = ./libft/libft.a
PRINTF = ./printf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: libft printf compile

libft: 
	@echo " ---> Compiling LIBFT <--- \n"
	@${MAKE} -C ./libft

printf: 
	@echo " ---> Compiling PRINTF <--- \n"
	@${MAKE} -C ./printf

compile: ${NAME}

$(NAME): ${OBJS}
	@echo " ---> Compiling push_swap <---\n"
	make -C ./libft
	make -C ./printf
	@${CC} ${OBJS} ${LIBFT} ${PRINTF} -o ${NAME}

clean:
	@${MAKE} -C ./libft clean
	@${MAKE} -C ./printf clean
	@${RM} ${OBJS}

fclean: clean
	@${MAKE} -C ./libft fclean
	@${MAKE} -C ./printf fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re libft compile
