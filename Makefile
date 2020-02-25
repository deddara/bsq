# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 14:26:58 by olaurine          #+#    #+#              #
#    Updated: 2020/02/25 21:05:57 by olaurine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_main.c ft_output.c ft_finder.c ft_atoi.c ft_init_matrix.c ft_init_matrix_2.c

NAME = bsq

HEADER = ft_bsq.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I $(HEADER) $(SRC) -o $(NAME)

test:
	./$(NAME) test1 test2 test3 test2

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
