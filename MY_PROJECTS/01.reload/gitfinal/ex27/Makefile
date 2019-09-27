#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbethany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 19:01:08 by kbethany          #+#    #+#              #
#    Updated: 2018/11/26 18:46:17 by kbethany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_display_file
SRC = display_file.c
OBJ = display_file.o
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): 
	gcc -c $(CFLAGS) $(SRC)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all