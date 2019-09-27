/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:03 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:02:46 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static size_t search_persent(t_flag *flag, char *str)
{
	size_t	index;

	index = 0;
	while (str[index] == ' ')
		index++;
	if (str[index] == '%')
	{
		flag->flag_5 = str[index];
		index++;
		return (index);
	}
	return(0);
}

int	is_it_flag(t_flag *flag, char *str1)
{
	char		str;

	str = *str1;
	if (str == 'c' || str == 'f' || str == 'd' || str == 's' ||
		str == 'i' || str == 'o' || str == 'u' || str == 'x' ||
		str == 'X' || str == 'p' || str == 'S')
		{
			flag->flag_5 = str;
			return (1);
		}
	return (search_persent(flag, str1));
}
