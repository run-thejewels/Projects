
FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fdf
SRC=src/*.c
OBJ=src/*.o
INCLUDES=include/libft/libft.a include/minilibx_macos/libmlx.a

all:
	@make -C include/libft/ all
	@make -C include/minilibx_macos/ all
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C include/libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C include/libft/ fclean

re: fclean all

push:
	git add .
	git status
	git commit -m fdf
	git push
