# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 01:18:09 by anraymon          #+#    #+#              #
#    Updated: 2023/12/05 01:18:09 by anraymon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   = push_swap

CC     = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS   = push_swap.c \
				srcs/list.c \
				srcs/list_annex.c \
				srcs/parser.c \
				srcs/instruction.c \
				srcs/algorithm.c \
				srcs/algorithm_f_utils.c \
				srcs/algorithm_f_tcheck.c \
				srcs/algorithm_f_smallest.c \
				srcs/algorithm_f_biggest.c \
				srcs/algorithm_f_inferior.c \
				srcs/algorithm_f_superior.c \

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: $(OBJS)
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS} ${NAME}

fclean: clean
	rm -f ${NAME}

re: clean all

.PHONY: all clean fclean re