# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhoppe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 13:57:57 by jhoppe            #+#    #+#              #
#    Updated: 2018/10/06 16:13:57 by njacobso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

SRC = *.c

all: clean fclean $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -o colle-2 $(SRC)

clean:
	rm -f ft_colle2.o

fclean:
	rm -rf colle-2

re: all clean
