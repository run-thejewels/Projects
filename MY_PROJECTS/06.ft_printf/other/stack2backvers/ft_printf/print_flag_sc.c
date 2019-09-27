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
	int		i;

	i = 0;
	if (flag->flag_5 == 's' || flag->flag_5 == 'S')
	{
		flag->str = ft_strdup(va_arg(*arguments, char*));
	//	printf("%s", flag->str);
		if (!(flag->str))
			flag->str = ft_strdup("(null)");
		return (printer(flag, i));
	}
	else if (flag->flag_5 == 'c')
	{
		i = va_arg(*arguments, int);
		if (i == 0)
			flag->str = ft_strdup("\0");
		else
			flag->str = ft_strdup((char*)&i);
		return (printer(flag, i));
	}
	else if (flag->flag_5 == '%')
	{
		flag->str = ft_strdup("%");
		return (printer(flag, i));
	}
	return (0);
}
