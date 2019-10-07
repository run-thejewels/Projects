# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: forange- <forange-@student.fr.42>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 16:00:22 by bsabre-c          #+#    #+#              #
#    Updated: 2019/10/06 17:34:11 by bsabre-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libft.a
FLAGS 	=	-g -Wall -Wextra -Werror -c
DIR_O 	=	objects

FILES 	=	ft_absi.c		ft_absll.c		ft_atoi.c		ft_atoll.c		\
			ft_bzero.c		ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
			ft_isdigit.c	ft_isprint.c	ft_itoa.c		ft_lltoa.c		\
			ft_lstadd.c		ft_lstdel.c		ft_lstdelone.c	ft_lstiter.c	\
			ft_lstmap.c		ft_lstnew.c		ft_memalloc.c	ft_memccpy.c	\
			ft_memchr.c		ft_memcmp.c		ft_memcpy.c		ft_memdel.c		\
			ft_memmove.c	ft_memset.c		ft_putchar.c	ft_putchar_fd.c	\
			ft_putendl.c	ft_putendl_fd.c	ft_putnbr.c		ft_putnbr_fd.c	\
			ft_putnbrll.c	ft_putstr.c		ft_putstr_fd.c	ft_strcat.c		\
			ft_strchr.c		ft_strclr.c		ft_strcmp.c		ft_strcpy.c		\
			ft_strdel.c		ft_strdup.c		ft_strequ.c		ft_striter.c	\
			ft_striteri.c	ft_strjoin.c	ft_strlcat.c	ft_strlen.c		\
			ft_strmap.c		ft_strmapi.c	ft_strncat.c	ft_strncmp.c	\
			ft_strncpy.c	ft_strnequ.c	ft_strnew.c		ft_strnstr.c	\
			ft_strrchr.c	ft_strsplit.c	ft_strstr.c		ft_strsub.c		\
			ft_strtrim.c	ft_tolower.c	ft_toupper.c	ft_lstnew_fag.c	\
			ft_list_bublesort.c		ft_list_murgesort.c 	ft_wstrlen.c	\
			ft_putwchar_fd.c		ft_putwstrn_fd.c		ft_strupr.c		\
			ft_ulltoa_base.c		ft_putchar_fd_smpl.c	ft_lltoa_base.c	\
			ft_sqr_int.c			ft_sqr_ll.c				ft_sqr_szt.c	\
			ft_strnewc.c			fprint_specifiers.c		fprint.c		\
			ft_max_i.c				ft_min_i.c				count_words.c	\
			ft_lstdel_fag.c

OBJECTS =	$(addprefix $(DIR_O)/,$(FILES:.c=.o))

OBJ		=	$(FILES:.c=.o)

$(NAME) :
			@echo "Compiling libft files"
			@mkdir $(DIR_O)
			@gcc $(FLAGS) $(FILES) && mv $(OBJ) $(DIR_O)
			@ar rc $(NAME) $(OBJECTS)
			@ranlib $(NAME)
			@echo "Done"

clean :
			@echo "remove libft object files and some trash"
			@rm -f $(OBJECTS)
			@rm -rf $(DIR_O)
			@rm -rf .DS_Store
			@echo "Done"

fclean : clean
			@echo "remove $(NAME)"
			@rm -f $(NAME)

%.o: %.c $(HEAD)
		    @gcc $(FLAGS) -c -o $@ $<

.PHONY: all, clean, fclean, re

all : $(NAME)

re: fclean all
