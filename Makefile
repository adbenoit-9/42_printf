# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 18:38:18 by adbenoit          #+#    #+#              #
#    Updated: 2019/12/04 18:27:15 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  ft_arg.c ft_putarg.c ft_putnbr_fd.c ft_atoi.c ft_putchar_fd.c ft_putstr_fd.c ft_printf.c ft_putnbr_base.c ft_strlen.c ft_putptr.c

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

RM	= rm -f

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

bonus:	${NAME}
	ar rc ${NAME}

all:	${NAME}

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY: all clean fclean re
