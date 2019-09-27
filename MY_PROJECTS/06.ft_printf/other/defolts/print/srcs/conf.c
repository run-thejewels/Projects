/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:33:02 by kbethany          #+#    #+#             */
/*   Updated: 2019/03/01 19:08:45 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	conf( t_printf s)
{
	size_t      i;

	i = 0;
	while (!(type(s.format[i])))
	{
		flags(format[i]);
		if ('0' <= format[i] && format[i] <= '9')
			s.width = ft_atoi(&(format[i]));
		if (format[i] == '.')
		{
			i++;
			s.precision = ft_atoi(&format[i]);
		}
		i++;
	}

}
