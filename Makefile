# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 18:38:18 by adbenoit          #+#    #+#              #
#    Updated: 2021/01/07 00:39:41 by adbenoit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

INC			= ./

HEADER		= $(INC)ft_printf.h

SRC_DIR	=	./

SRC			= 	ft_setformat.c		print_arg.c \
				print_ux.c			print_p.c \
				print_c.c			print_s.c \
				ft_printf.c			print_d.c

LIB_DIR		=	libft/

LIB			=	$(LIB_DIR)libft.a

LIB_OBJ		=	$(LIB_DIR)obj/*.o

OBJ_DIR	=	obj/

OBJ_NAME	=	$(SRC:.c=.o)

OBJ			=	$(addprefix $(OBJ_DIR),$(OBJ_NAME))

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:	$(LIB) $(NAME)

$(LIB) :
	@make -C $(LIB_DIR)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) $(LIB_OBJ)
	@printf "\n"
	@echo "Compilation of \033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADER)
	@printf "\033[34;1m|\033[0;m"
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@gcc $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make -C $(LIB_DIR) clean
	@echo "\033[33;1mFt_printf\033[0;1m: objects deleted\033[0m"

fclean: clean
	@$(RM) $(NAME) 
	@make -C $(LIB_DIR) fclean
	@echo "\033[33;1mFt_printf\033[0;1m: $(NAME) deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re
