#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 16:43:21 by ajon-hol          #+#    #+#              #
#    Updated: 2018/10/03 17:03:09 by ajon-hol         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bsq
SRC = src/*.c
INCLUDES = includes
OBJECTS = *.o
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): 
	gcc -I$(INCLUDES) $(CFLAGS) -c $(SRC)
	gcc $(CFLAGS) -I$(INCLUDES) -o $(NAME) main.c $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
