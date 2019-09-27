# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rymuller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 12:31:51 by rymuller          #+#    #+#              #
#    Updated: 2019/06/30 15:30:33 by rymuller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 := checker
NAME2 := push_swap

SRC :=	check_argv_and_placing_stack.c \
		doubly_linked_list_for_pvt_stack_b.c \
		doubly_linked_list_for_stacks.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c

SRC_CHR :=	checker.c

SRC_PSH :=	push_swap.c \
			quicksort.c \
			pivots_operations.c \
			doubly_linked_list_for_sort_command.c \
			optimizing_sort_algorithm.c \
			sort_triple_a.c

CFLAGS := -Wall -Wextra -Werror
HEADER := -I./libft/includes
LIB := -L./libft -lft -L./ft_printf -lftprintf

all: $(NAME1) $(NAME2)

$(NAME1): $(SRC) $(SRC_CHR)
	make -C libft
	make -C ft_printf
	gcc $(CFLAGS) $(HEADER) $(SRC) $(SRC_CHR) $(LIB) -o $(NAME1)

$(NAME2): $(SRC) $(SRC_PSH)
	gcc $(CFLAGS) $(HEADER) $(SRC) $(SRC_PSH) $(LIB) -o $(NAME2)

clean:
	make -C libft clean
	make -C ft_printf clean

fclean:
	make -C libft fclean
	make -C ft_printf fclean
	rm -rf $(NAME1) $(NAME2)

re: fclean all

.PHONY: clean flcean all re
