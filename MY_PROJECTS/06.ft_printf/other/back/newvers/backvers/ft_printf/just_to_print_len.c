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
	if (str[index] == '%')
		*persent_indicate = 1;
	else
		*persent_indicate = 0;
	*count += index;
	return (index);
}
