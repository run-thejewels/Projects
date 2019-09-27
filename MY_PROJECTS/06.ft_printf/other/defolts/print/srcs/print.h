/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:29:35 by kbethany          #+#    #+#             */
/*   Updated: 2019/03/01 19:10:48 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PRINT_H
# define PRINT_H
# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		type(char a);
void	conf( t_printf s);
size_t	digit(int n, int t);
char	*ft_itoa_base(int value, int base);
size_t	myputstr(char const *str);

typedef	struct	s_printf
{
	INT_MAX		t;
    va_list		ap;
    char		*format;
    char		flag;
    int			width;
    int			precision;
    int			type;
}				t_printf;

#endif
