# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlam <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 16:16:43 by tlam              #+#    #+#              #
#    Updated: 2023/09/27 17:59:30 by tlam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= do-op
SRCS	= main.c srcs/sources.c srcs/operations.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes/
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
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
