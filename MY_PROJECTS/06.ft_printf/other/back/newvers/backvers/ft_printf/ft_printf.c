/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:49:02 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:00:10 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_printf(const char *format, ...)
{
	char	*str;
	int		p_indicate;
	va_list	arguments;
	int		count;

	count = 0;
	str = (char *)format;
	va_start(arguments, format);
	while (*str)
	{
		str = ft_putstr_len(str, just_to_print_len(str, &p_indicate, &count));
		if (p_indicate)
			str = post_persent(str, &arguments, &count);
	}
	va_end(arguments);
	return (count);
}
