#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbethany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/24 16:19:35 by kbethany          #+#    #+#              #
#    Updated: 2019/08/24 17:28:23 by kbethany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_SWAP = push_swap
NAME_CHEK = checker
RM = /bin/rm -rfv
LIBFT_F = ../libft/
LIBFT = libft.a
OUT = ../
CFILES = main.c
CFILES += errors_ps.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@if [ ! -e $(LIBFT_F)$(LIBFT) ]; then \
		make -C $(LIBFT_F); \
	fi
	@if [ -e $(LIBFT_F)$(LIBFT) ]; then \
		echo "$(NAME) compiling... \c"; \
		gcc -Wall -Wextra -Werror -c $(CFILES); \
		gcc -Wall -Wextra -Werror $(OFILES)  $(LIBFT_F)$(LIBFT) -o $(NAME); \
		cp $(NAME) $(OUT); \
		echo "$(NAME) compiled"; \
	else \
		echo "something wrong with $(LIBFT) or/and $SLIB) libraries"; \
	fi

clean:
	@$(RM) $(OFILES) | wc -l | tr '\n' ' ' && echo ft_*.o files deleted

fclean: clean
	@$(RM) $(NAME) | wc -l | tr '\n' ' ' && echo $(NAME) deleted

re: fclean all