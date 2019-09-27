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

size_t	print_flag_sc(t_flag *flag, va_list *arguments)
{
//	char	a;
	int		i;

	i = 0;
	// a = 0;
	// ft_putstr(" final :");
	//  ft_putchar(flag->flag_5);
	//  ft_putstr("\n");
	if (flag->flag_5 == 's' || flag->flag_5 == 'S')
	{
		flag->str = va_arg(*arguments, char*);
		if (flag->str == 0)
			flag->str = NULL;
		return (printer(flag, i));
	}
	else if (flag->flag_5 == 'c')
	{
		i = va_arg(*arguments, int);
		flag->str = (char*)&i;
		if (i == 0)
			flag->str = "";
		return (printer(flag, i));
	}
	else if (flag->flag_5 == '%')
	{
//		ft_putstr("lol");
		flag->str = ft_strdup("%");
		return (printer(flag, i));
	}
	return (0);
}
