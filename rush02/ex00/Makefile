# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flboulea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 15:00:19 by flboulea          #+#    #+#              #
#    Updated: 2023/09/24 01:33:20 by flboulea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c srcs/*.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= rush-02
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
RM		= rm -f

.c.o:
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME} -I ${INCS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
