/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_sc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:35:44 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:17:18 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_sc(t_flag *flag, va_list *arguments, size_t *s)
{
	int		i;

	i = 0;
	if (flag->flag_5 == 's' || flag->flag_5 == 'S')
	{
		if (!(flag->str = ft_strdup(va_arg(*arguments, char *))))
			flag->str = ft_strdup("(null)");
		return (printer(flag, i));
	}
	else if (flag->flag_5 == 'c' || flag->flag_5 == 'C')
	{
		i = va_arg(*arguments, int);
		if (i)
			flag->str = ft_strdup_n((char*)&i, 1);
		else
		{
			flag->str = ft_strdup("^@");
			*s += 1;
		}
		return (printer(flag, i));
	}
	else if (flag->flag_5 == '%')
	{
		flag->str = ft_strdup("%");
		return (printer(flag, i));
	}
	return (0);
}
