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

size_t	check_flags(char *str, t_flag *flag)
{
	size_t index;

	index = 0;
	while (str[index])
	{
		if (flag_end(str[index]))
		{
			flag->flag_5 = str[index];
			index++;
			break ;
		}
		else if (ok(str + index, flag))
			index += ok(str + index, flag);
		else
			return (0);
	}
	if (!only_1_flag(flag))
		return (0);
	return (index);
}
