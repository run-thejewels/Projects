/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:30:02 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:13:46 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_o(t_flag *flag, va_list *arguments)
{
	unsigned long long int	i;

	if (flag->l)
	{
		i = va_arg(*arguments, unsigned long int);
		flag->str = ft_itoa_base_long(flag, i, 8);
	}
	if (flag->ll)
	{
		i = va_arg(*arguments, unsigned long long int);
		flag->str = ft_itoa_base_long(flag, i, 8);
	}
	else
	{
		i = va_arg(*arguments, unsigned int);
		flag->str = ft_itoa_base_long(flag, i, 8);
	}
	return (printer(flag, i));
}
