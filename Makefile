# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 10:39:55 by ybesbes           #+#    #+#              #
#    Updated: 2020/07/28 20:56:54 by ybesbes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	srcs/ft_printf.c	srcs/ft_treatment.c	srcs/ft_read.c	srcs/ft_read2.c	srcs/ft_parsing.c	\
		srcs/ft_libft3.c	srcs/ft_printflibft.c	srcs/ft_printflibft2.c	srcs/ft_format.c	\

INCLUDES = includes

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c -I ${INCLUDES} $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:	${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
