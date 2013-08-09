#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouvet <yann.bouvet@voila.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/09 10:45:53 by ybouvet           #+#    #+#              #
#    Updated: 2013/08/09 11:09:35 by ybouvet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		calc

SRC =		main.c \
			evalexpr/eval_expr.c \
			evalexpr/eval_op.c \
			evalexpr/read.c \
			evalexpr/operation/add_sub.c \
			evalexpr/operation/div_mod.c \
			evalexpr/operation/mult.c \
			evalexpr/operation/operation.c \
			evalexpr/utility/ft_test.c \
			evalexpr/utility/util_big.c \
			evalexpr/utility/util_operation.c \

INCLUDE =	includes/

OBJ =		$(SRC:.c=.o)

CFLAGS =	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) -I$(INCLUDE) $(OBJ)

clean:
			/bin/rm -f $(OBJ)

flcean:		clean
			/bin/rm -f $(NAME)
