#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbethany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 19:01:08 by kbethany          #+#    #+#              #
#    Updated: 2019/01/07 15:38:58 by kbethany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
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