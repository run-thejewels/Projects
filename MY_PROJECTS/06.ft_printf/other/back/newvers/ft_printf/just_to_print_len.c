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

size_t	just_to_print_len(char *str, int *persent_indicate, int *count)
{
	size_t index;

	index = 0;
	while (str[index] && str[index] != '%')
		index++;
	ft_putstr_len(str, index);
	if (str[index] == '%')
	{
		index++;
		if (is_it_flag(&str[index]) >= 0)
			*persent_indicate = 1;
		else
			index -= is_it_flag(&str[index]);
	}
	else
		*persent_indicate = 0;
	*count += index;
	return (index);
}
