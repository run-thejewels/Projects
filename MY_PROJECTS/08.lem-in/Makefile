# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/16 14:32:21 by bsabre-c          #+#    #+#              #
#    Updated: 2019/10/06 17:52:48 by bsabre-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem-in
FLAGS		= -Wall -Wextra -Werror -g 

# directories
DIR		=	./

# files
SRC_LEMIN	= $(DIR)main.c					$(DIR)new_room.c				\
			  $(DIR)read_rooms.c			$(DIR)gnl.c						\
			  $(DIR)get_first_last_room.c	$(DIR)temp.c					\
			  $(DIR)free.c					$(DIR)make_linkage_1.c			\
			  $(DIR)array.c					$(DIR)dijkstra_1.c				\
			  $(DIR)karpov_globchansky_1.c	$(DIR)dijkstra_2.c				\
			  $(DIR)karpov_globchansky_2.c	$(DIR)queue.c					\
			  $(DIR)karpov_globchansky_3.c	$(DIR)cpy_way_array.c			\
			  $(DIR)karpov_globchansky_4.c	$(DIR)kill_tlist.c				\
			  $(DIR)prepare_ant_queue.c		$(DIR)print_ant_queues.c		\
			  $(DIR)make_linkage_2.c		$(DIR)teleport_ants.c
SRC_GRAFIX	= $(DIR)grafix.c				$(DIR)grafix_hooks.c			\
			  $(DIR)grafix_draw_line.c		$(DIR)grafix_draw_room_web.c	\
			  $(DIR)grafix_draw_ants.c		$(DIR)grafix_make_step.c		\
			  $(DIR)grafix_insert_rooms.c	$(DIR)grafix_insert_ants.c
HEAD		= $(DIR)lem_in.h
MLX			= mlx/libmlx.a -lmlx -framework OpenGL -framework AppKit

# libraries
L_FT 		= ./libft/
L_FT_A 		= $(L_FT)libft.a

$(NAME) :
			@make -sC $(L_FT)
			@echo "Compiling lem_in"
			@gcc $(FLAGS) $(SRC_LEMIN) $(SRC_GRAFIX) -I$(HEAD) $(L_FT_A) $(MLX) -o $(NAME)
			@rm -rf $(NAME).dSYM
			@echo "file $(NAME) was created succesfully"

clean :
			@echo "start cleaning"
			@make clean -sC $(L_FT)
			@rm -rf .DS_Store
			@rm -rf $(L_FT).DS_Store
			@echo "cleaning finished"

fclean : clean
			@rm -f $(L_FT_A)
			@rm -f $(NAME)
			@rm -rf $(NAME).dSYM
			@rm -f log.txt

lemin :
			@rm -f log.txt
			@touch log.txt
			chmod 777 log.txt
			@./$(NAME) -error < maps/src01
			@rm -rf $(NAME).dSYM

all : $(NAME)

%.o: %.c $(HEAD)
	    	@gcc $(FLAGS) -c -o $@ $<

.PHONY: all, clean, fclean, re

re: fclean all
