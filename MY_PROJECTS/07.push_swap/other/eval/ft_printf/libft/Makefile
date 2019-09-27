# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 21:16:10 by ahalmon-          #+#    #+#              #
#    Updated: 2019/04/13 20:16:14 by ahalmon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_putnbr_fd.c ft_putstr.c ft_atoi.c ft_putstr_fd.c ft_bzero.c \
ft_math_root.c ft_numch.c ft_strcat.c ft_isalnum.c ft_strchr.c \
ft_isalpha.c ft_strclr.c ft_isascii.c ft_strcmp.c ft_isdigit.c ft_strcpy.c \
ft_isprint.c ft_strdel.c ft_itoa.c ft_strdup.c ft_letter_replacement.c \
ft_strequ.c ft_lstadd.c ft_striter.c ft_lstdel.c ft_striteri.c ft_lstdelone.c \
ft_strjoin.c ft_lstiter.c ft_strlcat.c ft_lstmap.c ft_strlen.c ft_lstnew.c \
ft_strmap.c ft_maxmin.c ft_strmapi.c ft_memalloc.c ft_strncat.c ft_memccpy.c \
ft_strncmp.c ft_memchr.c ft_strncpy.c ft_memcmp.c ft_strnequ.c ft_memcpy.c \
ft_strnew.c ft_memdel.c ft_strnstr.c ft_memmove.c ft_strrchr.c ft_memset.c \
ft_strsplit.c ft_print_two_dimensional_array.c ft_strstr.c ft_putchar.c \
ft_strsub.c ft_putchar_fd.c ft_strtrim.c ft_putendl.c ft_tolower.c \
ft_putendl_fd.c ft_toupper.c ft_putnbr.c ft_binary_lstnew.c \
ft_binary_lstadd.c ft_binary_lst_strdel.c \
ft_binary_lst_search_content.c ft_binary_lst_search_cs.c \
ft_binary_lst_search_str_content.c ft_lstsearch_content.c ft_lstsearch_cs.c \
ft_lstsearch_str_content.c get_next_line.c \
ft_lst_free_chain.c ft_lst_turn.c ft_lst_chain_len.c ft_lst_unit_transfer.c \
ft_lstsearch_index.c ft_lstadd_to_end.c ft_math_rounding_down_float.c \
ft_itoa_float.c ft_itoa_long.c ft_itoa_double.c ft_itoa_long_double_old.c \
ft_itoa_long_long.c ft_math_rounding_down_double.c \
ft_math_rounding_down_l_double.c ft_math_numlen_long.c \
ft_math_numlen_long_double.c ft_math_long_double_normilize.c \
ft_strjoin_free_both.c ft_strjoin_free_1.c ft_strjoin_free_2.c \
ft_new_null_str.c ft_range_str.c ft_lstdel_complite.c ft_sort_quick.c \
ft_jump_pointer_to_n.c ft_swap_byte.c ft_swap_n_bytes.c ft_strlen_safe.c \
ft_str_disnuller_end.c ft_strdup_free.c ft_lst_monolith_from_array.c \
ft_lstnew_no_copy.c ft_lst_to_array.c ft_lst_to_array_nullterm.c \
ft_lst_to_array_free.c ft_lst_to_array_nullterm_free.c \
ft_lst_sort_quick.c ft_lst_monolith_lstnew.c ft_lst_monolith_sort_quick.c \
ft_lst_monolith_convert_to_monolith.c ft_lst_get_end.c \
ft_this_files_is_same.c ft_free_both.c ft_itoa_long_double_wrapper.c \
ft_lst_stack_is_empty.c ft_lst_stack_keep_stacks.c ft_lst_stack_new_stack.c \
ft_lst_stack_pop.c ft_lst_stack_push.c ft_lst_stack_top.c \
ft_lst_stack_empty_stack_num_tightly.c ft_lst_stack_empty_stack_num.c \
ft_lst_stack_size.c ft_putstr_len.c ft_putstr_len_fd.c ft_isspace.c \
ft_strcmp_no_spaces.c ft_strnew_filler.c ft_strdup_n.c ft_strdup_n_free.c \
ft_str_width.c ft_str_width_free.c \
ft_free_two_dimensional_array.c ft_lst_cut.c ft_lstsearch_cs_replace.c \
ft_mem_reverse.c ft_str_reverse.c ft_open_file_readonly.c ft_get_file.c \
ft_lst_all_content_size.c ft_math_module_int.c ft_lst_strlen.c \
ft_lst_strjoin.c ft_strnew_not_bzero.c ft_lst_strjoin_free.c \
ft_lst_strnew.c ft_jump.c ft_lst_join.c \
ft_lstsearch_cs_del.c ft_str_upper.c ft_str_lower.c ft_bits_write_bit.c \
ft_bits_reverse_bits_in_byte.c ft_bits_reverse_bits_in_bytes.c \
ft_bits_reverse_memory.c ft_bits_read_bit.c ft_bits_filler.c \
ft_bits_shift_left.c ft_bits_shift_right.c ft_bits_shift.c \
ft_issorted.c ft_lst_putstr_free.c ft_lst_strjoin_counter_out.c \
ft_lst_strjoin_counter_out_free.c ft_atoi_llu.c ft_itoa_llu.c \
ft_lst_strjoin_counter_out_free_cs.c ft_lst_putstr_free_cs.c \
ft_lst_strjoin_counter_out_cs.c ft_memcpy_safe.c \
ft_strsplit_spaces.c ft_lst_strjoin_free_cs.c ft_lst_strjoin_cs.c \
ft_lst_deduplication.c ft_lst_unit_transfer_with_malloc.c \
ft_lst_copy_chain.c ft_lst_putstr_sep.c ft_lst_putstr_sep_free.c \
ft_lst_strjoin_sep.c ft_lst_strjoin_sep_free.c \
ft_lst_strjoin_sep_counter_out.c ft_lst_strjoin_sep_counter_out_free.c \
ft_memdup.c ft_get_all_files_free.c ft_get_all_files.c \
ft_get_arguments_command_line.c ft_this_all_files_is_same.c \
ft_this_all_files_is_same_free.c \
ft_bits_print.c ft_bits_to_string.c ft_memjoin.c \
ft_math_longar_str_multi.c \
ft_math_longar_str_add_free_both.c \
ft_math_longar_str_exponent_mix.c \
ft_math_longar_str_add.c \
ft_math_longar_str_add_free_1.c \
ft_math_longar_str_comparison.c \
ft_math_longar_str_multi_free_1.c ft_bits_copy.c \
ft_math_longar_str_multi_free_both.c \
ft_bits_listing.c ft_math_longar_str_subtraction.c ft_free.c \
ft_math_longar_str_exponent_mix_free.c ft_math_longar_str_division.c \
ft_math_longar_str_remainder_of_division.c ft_free_and_return.c \
ft_issign.c ft_lst_cut_numbers.c ft_nuller_double_point.c \
ft_nuller_double_size_t.c \
ft_lst_stack_turn.c ft_lst_stack_push_back.c ft_memjoin_free_1.c
OUT = $(FILES:.c=.o)
INCLUDES = includes/

all:  $(NAME)


$(NAME): $(FILES)
	@gcc -g -Wall -Werror -Wextra -c $(FILES) -I $(INCLUDES)
		@ar rc $(NAME) $(OUT)
			@ranlib $(NAME)
clean:
	@/bin/rm -f $(OUT)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
