/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 21:20:15 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 18:43:43 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 20

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_two_list
{
	void				*content;
	size_t				content_size;
	struct s_two_list	*next;
	struct s_two_list	*back;
}						t_two_list;

typedef struct			s_iterators
{
	t_list				*lst;
	int					in;
	char				*s;
	int					work;
	char				*chr;
	t_list				*l;
}						t_iter;

void					ft_binary_lst_strdel(t_two_list **alst);
void					ft_binary_lstadd(t_two_list **alst, t_two_list *new);
t_two_list				*ft_binary_lstnew(void const *content, \
	size_t content_size);
t_two_list				*ft_binary_lstsea_cs(t_two_list *alst, \
	size_t to_search);
t_two_list				*ft_binary_lstseaconb(t_two_list *alst, \
	void *to_search);
t_two_list				*ft_binary_lstseacon(t_two_list *alst, char *to_search);
float					ft_math_root(float num, unsigned int root_index);
long long int			ft_maxmin(char *type, char *maxmin);
size_t					ft_numch(char *str, char ch);
char					*ft_letter_replacement(char *str, char previous, \
	char new);
void					ft_print_two_dimensional_array(char **str);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
int						ft_isalnum(int ch);
int						ft_isalpha(int ch);
int						ft_isascii(int ch);
int						ft_isdigit(int ch);
int						ft_isprint(int ch);
int						ft_isspace(int ch);
char					*ft_itoa(int n);
char					*ft_itoa_long(long int n);
char					*ft_itoa_long_long(long long int n);
char					*ft_itoa_float(float num);
char					*ft_itoa_double(double num);
char					*ft_itoa_long_double_old(long double num, size_t \
	accuracy);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lst_cut(t_list **list, t_list **previous);
void					ft_lstdelone(t_list **alst, \
	void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
t_list					*ft_lstnew_no_copy(void *content, \
	size_t content_size);
t_list					*ft_lst_monolith_lstnew(void *content, \
	void *new_lst, size_t content_size);
void					ft_lst_monolith_sort_quick(t_list *lst_mono, \
	int (*f)(void *, void *));
size_t					ft_lst_putstr_free(t_list *lst);
t_list					*ft_lst_monolith_convert_to_monolith(t_list *lst);
t_list					*ft_lst_monolith_from_array(void *arr, \
	size_t size, size_t amount);
t_list					*ft_lstsearch_cs(t_list *lst, size_t cs);
t_list					*ft_lstsearch_cs_replace(t_list **lst, size_t cs);
t_list					*ft_lstsearch_cs_del(t_list *lst, size_t cs);
t_list					*ft_lstsearch_content(t_list *lst, \
	void *to_search, size_t search_size);
t_list					*ft_lstsearch_str_content(t_list *lst, char *to_search);
void					ft_lst_free_chain(t_list *chain);
t_list					*ft_lst_turn(t_list *begin);
t_list					*ft_lst_join(t_list *first, t_list *second);
char					*ft_lst_strjoin(t_list *lst);
char					*ft_lst_strjoin_fr(t_list *lst);
char					*ft_lst_strjoin_counter_out(t_list *lst, \
	size_t *counter);
char					*ft_lst_strjoin_counter_out_free(t_list *lst, \
	size_t *counter);
char					*ft_putstr_len(char const *s, size_t len);
char					*ft_putstr_len_fd(char const *s, size_t len, int fd);
size_t					ft_lst_chain_len(t_list *begin);
t_list					*ft_lst_unit_transfer(t_list *lst);
t_list					*ft_lst_unit_transfer_with_malloc(t_list *lst);
t_list					*ft_lstsearch_index(t_list *lst, size_t index);
void					ft_lstadd_to_end(t_list **alst, t_list *new);
void					ft_lstdel_complite(t_list **this, t_list **first_elem);
void					*ft_lst_to_array(t_list *lst);
void					*ft_lst_to_array_free(t_list *lst);
void					*ft_lst_to_array_nullterm(t_list *lst);
void					*ft_lst_to_array_nullterm_free(t_list *lst);
t_list					*ft_lst_sort_quick(t_list *lst, \
	int (*f)(void *, void *));
t_list					*ft_lst_get_end(t_list *lst);
size_t					ft_lst_strlen(t_list *lst);
t_list					*ft_lst_strnew(char *str);
int						ft_lst_stack_is_empty(size_t channel);
t_list					**ft_lst_stack_keep_stacks(int free_all);
t_list					*ft_lst_stack_new_stack(size_t channel);
void					*ft_lst_stack_pop(size_t channel);
int						ft_lst_stack_push(size_t channel, \
	void *content, size_t content_size);
void					*ft_lst_stack_top(size_t channel);
size_t					ft_lst_stack_empty_stack_num(void);
size_t					ft_lst_stack_empty_stack_num_tightly(void);
size_t					ft_lst_stack_size(size_t channel);
size_t					ft_lst_strlen_cs(t_list *lst);
char					*ft_lst_strjoin_counter_out_free_cs(t_list *lst, \
	size_t *counter);
char					*ft_lst_strjoin_counter_out_cs(t_list *lst, \
	size_t *counter);
char					*ft_lst_strjoin_cs(t_list *lst);
char					*ft_lst_strjoin_free_cs(t_list *lst);
size_t					ft_lst_putstr_free_cs(t_list *lst);
t_list					*ft_lst_deduplication(t_list *orig);
char					*ft_lst_strjoin_sep(t_list *lst, char *separator);
char					*ft_lst_strjoin_sep_free(t_list *lst, char *separator);
char					*ft_lst_strjoin_sep_counter_out(t_list *lst, \
	char *separator, size_t *counter);
char					*ft_lst_strjoin_sep_counter_out_free(t_list *lst, \
	char *separator, size_t *counter);
size_t					ft_lst_putstr_sep(t_list *lst, char *separator);
size_t					ft_lst_putstr_sep_free(t_list *lst, char *separator);
t_list					*ft_lst_copy_chain(t_list *lst);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *d, const void *s, int ch, size_t c);
void					*ft_memchr(const void *buffer, int ch, size_t count);
int						ft_memcmp(const void *mem1, const void *mem2, size_t n);
void					*ft_memcpy(void *destptr, const void *srcptr, \
	size_t num);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dest, const void *source, \
	size_t count);
void					*ft_memset(void *destination, int c, size_t n);
void					ft_putchar_fd(char c, int fd);
void					ft_putchar(char c);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putendl(char const *s);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putstr(char const *s);
char					*ft_strcat(char *str1, const char *str2);
char					*ft_strchr(const char *string, int symbol);
void					ft_strclr(char *s);
int						ft_strcmp(const char *str1, const char *str2);
char					*ft_strcpy(char *str1, const char *str2);
void					ft_strdel(char **as);
char					*ft_strdup(const char *src);
char					*ft_strdup_free(char *src);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *str1, const char *str2, size_t num);
size_t					ft_strlen(const char *string);
size_t					ft_strlen_safe(const char *string);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, \
	char (*f)(unsigned int, char));
char					*ft_strncat(char *str1, const char *str2, size_t num);
int						ft_strncmp(const char *str1, const char *str2, \
	size_t num);
char					*ft_strncpy(char *dest, const char *source, \
	size_t count);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnew_not_bzero(size_t size);
char					*ft_strnstr(const char *str1, const char *str2, \
	size_t len);
char					*ft_strrchr(const char *string, int symbol);
char					**ft_strsplit(char const *s, char c);
char					**ft_strsplit_spaces(char const *s);
char					*ft_strstr(const char *str1, const char *str2);
char					*ft_strsub(char const *s, unsigned int start, \
	size_t len);
char					*ft_strtrim(char const *s);
int						ft_tolower(int ch);
int						ft_toupper(int ch);
int						get_next_line(const int fd, char **line);
float					ft_math_rounding_down_float(float num);
long long int			ft_math_rounding_down_double(double num);
long double				ft_math_rounding_down_l_double(long double num);
size_t					ft_math_numlen_long(long int num);
size_t					ft_math_numlen_long_double(long double num);
size_t					ft_math_long_double_normilize(long double *num);
int						ft_math_module_int(int num);
char					*ft_strjoin_free_1(char *s1, char *s2);
char					*ft_strjoin_free_2(char *s1, char *s2);
char					*ft_strjoin_fr_both(char *s1, char *s2);
char					*ft_new_null_str(size_t size);
char					ft_range_str(char *str);
void					ft_swap_byte(void *x, void *y);
void					ft_swap_n_bytes(void *a, void *b, size_t n);
void					*ft_jump_pointer_to_n(void *pointer, int n);
void					*ft_jump(void *pointer, size_t n);
void					ft_sort_quick(void *arr, size_t size, \
	size_t amount, int (*f)(void *, void *));
char					*ft_str_disnuller_end(char *str);
int						ft_this_files_is_same(char *fn1, char *fn2);
void					*ft_free_both(void *p1, void *p2);
char					*ft_itoa_long_double_wrapper(long double num, \
	size_t accuracy);
int						ft_strcmp_no_spaces(const char *str1, const char *str2);
char					*ft_strnew_filler(size_t size, char filler);
char					*ft_strdup_n(const char *src, size_t n);
char					*ft_strdup_n_free(char *src, size_t n);
char					*ft_str_width(char *str, \
	char filler, size_t len, char *flags);
char					*ft_str_width_free(char *str, \
	char filler, size_t len, char *flags);
void					ft_free_two_dimensional_array(void **arr);
void					ft_mem_reverse(void *mem, size_t size, size_t amount);
char					*ft_str_reverse(char *str);
int						ft_open_file_readonly(char *path);
size_t					ft_lst_all_content_size(t_list *lst);
void					*ft_get_file(char *path, size_t *size);
char					*ft_str_lower(char *str);
char					*ft_str_upper(char *str);
void					ft_bits_write_bit(void *byte, \
	size_t num_bit, unsigned char value);
unsigned char			ft_bits_read_bit(void *byte, size_t num_bit);
void					ft_bits_reverse_bits_in_byte(void *byte);
void					ft_bits_reverse_bits_in_bytes(void *byte, \
	size_t num_bytes);
void					ft_bits_reverse_memory(void *memory, size_t mem_size);
void					ft_bits_filler(void *mem, size_t first_bit, \
	size_t num_bits, unsigned char value);
void					ft_bits_shift_right(void *mem, size_t size_bytes, \
	size_t shift_bits);
void					ft_bits_shift_left(void *mem, \
	size_t size_bytes, size_t shift_bits);
void					ft_bits_shift(void *mem, size_t size_bytes, \
	size_t shift_bits, char *direction);
int						ft_issorted(void *array, size_t arr_size, \
	size_t piece_size, int (*f)(void *, void *));
unsigned long long int	ft_atoi_llu(char *str);
char					*ft_itoa_llu(unsigned long long int num);
void					*ft_memcpy_safe(void *destptr, const void *srcptr, \
	size_t num);
void					*ft_memdup(void *mem, size_t size);
void					*ft_memjoin(void *mem_1, \
	size_t size_1, void *mem_2, size_t size_2);
t_list					*ft_get_all_files_free(t_list *paths);
t_list					*ft_get_all_files(t_list *paths);
t_list					*ft_get_arguments_command_line(int argc, char **argv);
int						ft_this_all_files_is_same(t_list *files);
int						ft_this_all_files_is_same_free(t_list *files);
char					*ft_math_longar_str_add(char *n1, char *n2);
void					ft_bits_print(void *mem, size_t num_bytes);
char					*ft_bits_to_string(void *mem, size_t num_bytes);
char					*ft_math_longar_str_multi(char *n1, char *n2);
char					*ft_math_longar_str_add_free_both(char *n1, \
	char *n2);
char					*ft_math_longar_str_add_free_1(char *n1, char *n2);
char					*ft_math_longar_str_exponent_mix(char *num, \
	unsigned long int exponent);
char					*ft_math_longar_str_add(char *n1, char *n2);
int						ft_math_longar_str_comparison(char *n1, char *n2);
char					*ft_math_longar_str_multi_free_both(char *n1, \
	char *n2);
char					*ft_math_longar_str_multi_free_1(char *n1, char *n2);
size_t					ft_bits_copy(void *src, void *dst, \
	size_t amount, size_t begin);
char					*ft_math_longar_str_multi_free_both(char *n1, char *n2);
char					*ft_bits_listing(void *mem, size_t num_bytes);
char					*ft_math_longar_str_subtraction(char *n1, char *n2);
void					*ft_free(void *p);
char					*ft_math_longar_str_exponent_mix_free(char *num, \
	unsigned long int exponent);
char					*ft_math_longar_str_division(char *n1, char *n2);
char					*ft_math_longar_str_remainder_of_division(char *n1, \
	char *n2);
void					*ft_free_and_return(void *to_free, void *to_return);
int						ft_issign(int ch);
t_list					*ft_lst_cut_numbers(char *exp);
void					ft_nuller_double_point(void **point_1, void **point_2);
void					ft_nuller_double_size_t(size_t *s_1, size_t *s_2);
char					*ft_math_longar_str_basic_calc(char *exp);
int						ft_lst_stack_turn(size_t channel);
int						ft_lst_stack_push_back(size_t channel, \
	void *content, size_t content_size);
void					*ft_memjoin_free_1(void *mem_1, \
	size_t size_1, void *mem_2, size_t size_2);

#endif
