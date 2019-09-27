/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:59:56 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 17:55:25 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	check_flags(char *str, t_flag *flag)
{
	size_t index;

	index = 0;
	flag_nuller(flag);
	while (str[index])
	{
		index += ok(str + index, flag);
		if ((index += is_it_flag(&str[index])))
		{
			flag->flag_5 = str[index];
			break ;
		}
		index++;
	}
	if (!only_1_flag(flag))
		return (0);
	return (index);
}
