/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:45:35 by kbethany          #+#    #+#             */
/*   Updated: 2019/03/01 19:09:09 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int		ft_printf(const char *format, ...)
{
	t_printf	s;
	size_t		i;
	size_t		c;

	i = 0;
	s.format = format;
	va_start(s.ap, format);
	while (s.format[i])
	{
		if (s.format[i] == '%')
			i = conf(s);
		if (0 < type(format[i]) && type(format[i]) < 5)
			c = c + digit(type(format[i]), va_arg(arg,int));
		if (type(format[i]) == 5)
            t = va_arg(arg,double);
		if (type(format[i]) == 6)
            t = va_arg(arg,wchar_t);
		if (type(format[i]) == 7)
            t = va_arg(arg,wchar_t*);
		if (type(format[i]) == 8)
            t = va_arg(arg,size_t);
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	c = c + i;
	return (c);
}
