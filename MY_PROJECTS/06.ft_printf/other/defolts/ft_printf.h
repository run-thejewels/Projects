/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:00:31 by kbethany          #+#    #+#             */
/*   Updated: 2019/03/04 16:18:42 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

typedef struct	s_printf
{
    va_list		ap;
	char		*format;
	char		flag;
	char		*form;
	int			width;
	int			precision;
	int			type;
}				t_printf;

size_t	just_to_print_len(char *str, int *persent_indicate, int *count);
char	*ft_putstr_len(char *str, size_t len);
size_t	recognise_types(char *str, va_list arguments);
char	*post_persent(char *str, va_list *arguments, int *count, );
int		ft_printf(const char *format, ...);
char	type(char a);
char	flag(char a);
size_t	diglen(int a);
char	*form(char *a);

#endif
 
