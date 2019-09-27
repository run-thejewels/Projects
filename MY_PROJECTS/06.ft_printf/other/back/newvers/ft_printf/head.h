/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 22:23:51 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/18 17:54:30 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/includes/libft.h"
# include <errno.h>

typedef struct			s_flags
{
	int 				null;
	int     		min;
	int 				sharp;
	int 				plus;
	int 				space;
	int					before_dot;
	char				before_flag;
	int					after_dot;
	char				after_flag;
	char				l;
	char				ll;
	char				h;
	char				hh;
	char				L;
	char				flag_5;
	char				*str;
	int					i;
}						t_flag;

int		printer(t_flag *flag, int i);
size_t	out_str(char *str);
void	first_flag_before(long long int i, t_flag *flag);
int		size_flag(char *a, t_flag *flag);
int		second_flag(char *a, t_flag *flag);
int		fixer_num(t_flag *flag);
void	fixer_str(t_flag *flag);
int		flag_begin_chek(char a, t_flag *flag);
char	*ft_strfilnew(size_t size, char a);
int		first_flag(long long int i, t_flag *flag, int f);
char	*ft_itoa_base_long(t_flag *flag, unsigned long long int value, int base);
size_t	print_flag_d(t_flag *flag, va_list *arguments);
size_t	print_flag_p(t_flag *flag, va_list *arguments);
char	*ft_upper(char *a);
char	*ft_lower(char *a);
size_t	print_flag_x(t_flag *flag, va_list *arguments);
size_t	print_flag_o(t_flag *flag, va_list *arguments);
size_t	print_flag_u(t_flag *flag, va_list *arguments);
size_t	print_flag_f(t_flag *flag, va_list *arguments);
size_t	print_flag_sc(t_flag *flag, va_list *arguments);

int		ft_printf(const char *format, ...);
size_t post_persent(char *str, va_list *arguments, int *count);
size_t	just_to_print_len(char *str, int *persent_indicate, int *count);
size_t	out_from_flag(t_flag *flag, va_list *arguments);

int		check_flags(char *str, t_flag *flag);
int		links_flag_prove(t_flag *flag);
int		is_it_flag(char *str1);
int		only_1_flag(t_flag *flag);
int		ok(char *str, t_flag *flag);
void	flag_nuller(t_flag *flag);

#endif
