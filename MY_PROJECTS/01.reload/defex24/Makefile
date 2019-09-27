#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbethany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 19:01:08 by kbethany          #+#    #+#              #
#    Updated: 2018/11/23 19:08:07 by kbethany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRC = src/*.c
INCLUDES = includes
OBJECTS = *.o
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): 
	gcc -c -I $(INCLUDES) $(CFLAGS) -c $(SRC)
	gcc $(CFLAGS) -I$(INCLUDES) -o $(NAME) main.c $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all