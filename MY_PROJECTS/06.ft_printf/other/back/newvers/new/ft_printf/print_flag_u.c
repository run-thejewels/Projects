/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:31:12 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:16:24 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_u(t_flag *flag, va_list *arguments)
{
	unsigned long long int	i;

	if (flag->l)
	{
		i = va_arg(*arguments, unsigned long int);
		flag->str = ft_itoa_long(i);
	}
	else if (flag->ll)
	{
		i = va_arg(*arguments, unsigned long long int);
		flag->str = ft_itoa_long_long(i);
	}
	else
	{
		i = va_arg(*arguments, unsigned int);
		flag->str = ft_itoa(i);
	}
	return (printer(flag, i));
}
