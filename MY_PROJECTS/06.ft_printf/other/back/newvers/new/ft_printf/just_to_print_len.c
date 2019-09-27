/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_to_print_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:02:06 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:03:31 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	just_to_print_len(char *str, int *persent_indicate)
{
	size_t i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i] && str[i] != '%')
		i++;
	ft_putstr_len(str, i);
	if (str[i] == '%')
	{
		i++;
		if (is_it_flag(&str[i]) >= 0)
		{
			*persent_indicate = 1;
			*count += i - 1;
			return (i);
		}
		else
			i -= is_it_flag(&str[i]);
	}
	else
	{
		*persent_indicate = 0;
		*count += i;
	}
	ft_putstr(" i: ");
	ft_putnbr(*count);
	ft_putstr("\n");
	return (i);
}
