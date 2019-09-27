/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:13:00 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:11:38 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_d(t_flag *flag, va_list *arguments)
{
	long long int	i;

	if (flag->l)
	{
		i = va_arg(*arguments, long int);
		flag->str = ft_itoa_long(i);
	}
	else if (flag->ll)
	{
		i = va_arg(*arguments, long long int);
		flag->str = ft_itoa_long_long(i);
	}
	else
	{
		i = va_arg(*arguments, int);
		flag->str = ft_itoa(i);
	}
	return (printer(flag, i));
}
