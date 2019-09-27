/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:28:50 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/22 15:29:39 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_x(t_flag *flag, va_list *arguments)
{
	unsigned long long int	i;

	if (flag->l)
	{
		i = va_arg(*arguments, unsigned long int);
		flag->str = ft_itoa_base_long(flag, i, 16);
	}
 	if (flag->ll)
	{
		i = va_arg(*arguments, unsigned long long int);
		flag->str = ft_itoa_base_long(flag, i, 16);
	}
	else
	{
		i = va_arg(*arguments,unsigned int);
		flag->str = ft_itoa_base_long(flag, i, 16);
	}
	if (flag->flag_5 == 'x')
		flag->str = ft_lower(flag->str);
	else
		flag->str = ft_upper(flag->str);
	return (printer(flag, i));
}
