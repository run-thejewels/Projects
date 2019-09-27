# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 15:38:31 by kfalia-f          #+#    #+#              #
#    Updated: 2019/01/26 18:56:58 by kfalia-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBNAME = libft.a

SRC = srcs/fillit.c \
	  srcs/ft_input.c \
	  srcs/ft_error.c \
	  srcs/ft_valid.c \
	  srcs/ft_recurs.c \
	  srcs/ft_alg.c \
	  srcs/ft_checkspot.c \
	  srcs/ft_clearspot.c \
	  srcs/ft_touch.c \
	  srcs/ft_newmap.c \
	  srcs/ft_output.c \
	  srcs/ft_coord.c \
	  srcs/ft_back.c

LIBSRC = libft/ft_atoi.c \
		 libft/ft_bzero.c \
		 libft/ft_isalnum.c \
		 libft/ft_isalpha.c \
		 libft/ft_isascii.c \
		 libft/ft_isdigit.c \
		 libft/ft_isprint.c \
		 libft/ft_itoa.c \
		 libft/ft_memalloc.c \
		 libft/ft_memccpy.c \
		 libft/ft_memchr.c \
		 libft/ft_memcmp.c \
		 libft/ft_memcpy.c \
		 libft/ft_memdel.c \
		 libft/ft_memmove.c \
		 libft/ft_memset.c \
		 libft/ft_putchar.c \
		 libft/ft_putchar_fd.c \
		 libft/ft_putendl.c \
		 libft/ft_putendl_fd.c \
		 libft/ft_putnbr.c \
		 libft/ft_putnbr_fd.c \
		 libft/ft_putstr.c \
		 libft/ft_putstr_fd.c \
		 libft/ft_strcat.c \
		 libft/ft_strchr.c \
		 libft/ft_strclr.c \
		 libft/ft_strcmp.c \
		 libft/ft_strcpy.c \
		 libft/ft_strdel.c \
		 libft/ft_strdup.c \
		 libft/ft_strequ.c \
		 libft/ft_striter.c \
		 libft/ft_striteri.c \
		 libft/ft_strjoin.c \
		 libft/ft_strlcat.c \
		 libft/ft_strlen.c \
		 libft/ft_strmap.c \
		 libft/ft_strmapi.c \
		 libft/ft_strncat.c \
		 libft/ft_strncmp.c \
		 libft/ft_strncpy.c \
		 libft/ft_strnequ.c \
		 libft/ft_strnew.c \
		 libft/ft_strnstr.c \
		 libft/ft_strrchr.c \
		 libft/ft_strsplit.c \
		 libft/ft_strstr.c \
		 libft/ft_strsub.c \
		 libft/ft_strtrim.c \
		 libft/ft_tolower.c \
		 libft/ft_toupper.c \
		 libft/ft_lstnew.c \
		 libft/ft_lstdelone.c \
		 libft/ft_lstdel.c \
		 libft/ft_lstdel.c \
		 libft/ft_lstiter.c \
		 libft/ft_lstmap.c \
		 libft/ft_lstadd.c \
		 libft/ft_strjoinre.c \
		 libft/ft_strexist.c \
		 libft/ft_strsplitgnl.c \
		 libft/ft_strchrint.c \
		 libft/ft_strdupre.c \
		 libft/ft_memalloc2.c \
		 libft/ft_charmin.c \
		 libft/ft_mass2del.c

OBJ = $(SRC:.c=.o)

LIBOBJ = $(LIBSRC:%.c=%.o)

INCLUDES = libft/includes/libft.h

LIB = libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	@gcc -c $(CFLAGS) $? -o $@

$(LIBNAME): $(LIBOBJ)
	@gcc -c $(CFLAGS) -I $(INCLUDES) $(LIBSRC)
	@rm -f *.o
	@ar rc $(LIBNAME) $(LIBOBJ)

$(NAME): $(LIBNAME)
	@gcc -o $(NAME) $(CFLAGS) -g $(SRC) $(LIB)

clean:
	@rm -f $(LIBOBJ)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(LIBNAME)
	@rm -f $(NAME)

re: fclean all
