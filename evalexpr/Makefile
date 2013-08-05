# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguinin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/07/31 14:34:32 by mguinin           #+#    #+#              #
#    Updated: 2013/08/02 14:50:59 by mguinin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
SRC = $(NAME).c eval_op.c read.c print.c
OBJ = $(NAME).o eval_op.o read.o print.o
FLAG = -Wextra -Wall -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) -I include $(SRC)
	gcc $(FLAG) -I include $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

