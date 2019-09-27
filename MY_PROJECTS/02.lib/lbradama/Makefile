#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbethany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 19:01:08 by kbethany          #+#    #+#              #
#    Updated: 2018/11/30 17:34:55 by kbethany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRC = *.c
OBJ = *.o
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): 
	gcc -c $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) 

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


test: 
	gcc tests.c -L. -lft -I./