.PHONY: all clean fclean re silent_clean silent_fclean silent_re

NAME = push_swap
RM = /bin/rm -rfv
RMS = /bin/rm -rf
SHARED_F = ../shared_s/
SLIB = slib.a
LIBFT_F = ../libft/
LIBFT = libft.a
OUT = ../
CFILES = main.c
CFILES += errors_ps.c
CFILES += structure_filler_ps.c
CFILES += operators_s_ps.c
CFILES += print_operations.c
CFILES += unfolding_arguments.c
CFILES += operators_p_ps.c
CFILES += operators_r_ps.c
CFILES += operators_rr_ps.c
CFILES += sorting_three.c
CFILES += search_max_min.c
CFILES += to_b.c
CFILES += is_sorted_ps.c
CFILES += algorithm_ps.c
CFILES += get_index.c
CFILES += final_turn.c
CFILES += fastest_cowboy.c
CFILES += how_many_steps.c
CFILES += to_a.c
CFILES += flags_filler.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@if [ ! -e $(SHARED_F)$(SLIB) ]; then \
		make silent_re -C $(SHARED_F); \
	fi
	@if [ ! -e $(LIBFT_F)$(LIBFT) ]; then \
		make silent_re -C $(LIBFT_F); \
	fi
	@if [ -e $(SHARED_F)$(SLIB) -a -e $(LIBFT_F)$(LIBFT) ]; then \
		echo "$(NAME) compiling... \c"; \
		gcc -Wall -Wextra -Werror -c $(CFILES); \
		gcc -Wall -Wextra -Werror $(OFILES) $(SHARED_F)$(SLIB) $(LIBFT_F)$(LIBFT) -o $(NAME); \
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

silent_clean:
	@$(RMS) $(OFILES)

silent_fclean: silent_clean
	@$(RMS) $(NAME)

silent_re: silent_fclean all
