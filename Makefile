# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 13:45:47 by gmolin            #+#    #+#              #
#    Updated: 2019/11/19 14:10:08 by gmolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS1 = srcs/board_mode.c srcs/create_mode.c srcs/placing_mode.c srcs/readjust_mode.c srcs/solve_mode.c srcs/main.c

OBJS = $(subst .c,.o,$(subst srcs/,,$(SRCS1)))

LIB = -L./libft -lft

INCL = -I ./srcs -I ./libft/includes/

all: libftcreator
	gcc $(FLAGS) -c $(SRCS1) $(INCL)
	gcc $(FLAGS) $(INCL) $(OBJS) $(LIB) -o $(NAME)

libftcreator:
	make -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	
re: clean all