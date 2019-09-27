#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbethany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 12:49:52 by kbethany          #+#    #+#              #
#    Updated: 2019/04/29 14:09:45 by kbethany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CHECKER =	checker
P_S =		push_swap

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror

P_S_SRC =		alg.c ft_strisdigit.c operations.c parsing.c pp.c push_swap.c\
						pushes.c rr.c shreder.c  simetra.c sort_b.c sorter.c ss.c\
						ft_error.c

CHECK_SRC =	checker.c alg.c ft_strisdigit.c operations.c parsing.c pp.c\
						pushes.c rr.c shreder.c  simetra.c sort_b.c sorter.c ss.c\
						ft_error.c

P_S_OBJ =	$(P_S_SRC:.c=.o)

CHECK_OBJ = $(CHECK_SRC:.c=.o)

INC =		include

PRINTPATH =	ft_printf/libftprintf.a

PRINTINC	=	ft_printf/includes

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -I $(PRINTINC) -c -o $@ $^

all: $(CHECKER) $(P_S)

$(CHECKER):
	@cd ft_printf; $(MAKE) -f Makefile
	@make $(CHECK_OBJ)
	@$(CC) $(CFLAGS) -o $(CHECKER) $(CHECK_OBJ) $(PRINTPATH)

$(P_S):
	@cd ft_printf; $(MAKE) -f Makefile
	@make $(P_S_OBJ)
	@$(CC) $(CFLAGS) -o $(P_S) $(P_S_OBJ) $(PRINTPATH)

clean:
	@cd ft_printf; $(MAKE) -f Makefile clean
	@rm -rf $(CHECK_OBJ) $(P_S_OBJ)

fclean: clean
	@rm -rf $(CHECKER) $(P_S) $(PRINTPATH)

re :fclean all
