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
LIBFTDIR = libft/
CC     = gcc
CFLAGS = -g #-Wall -Wextra -Werror

#INCLUDE = -L ./libft -lft 

SRCS   = push_swap.c \
				srcs/list.c \
				srcs/list_annex.c \
				srcs/parser.c \
				srcs/instruction.c \
				srcs/algorithm.c \
				srcs/algorithm_annex.c \

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}: $(OBJS)
	${CC} ${FLAGS} ${OBJS} -o ${NAME}
#	make -C $(LIBFTDIR)

#${INCLUDE}
clean:
	rm -f ${OBJS} ${NAME}
#	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	rm -f ${NAME}
#	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re