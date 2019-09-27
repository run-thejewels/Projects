/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_begin_chek.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:09:22 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 17:56:53 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	flag_begin_chek(char *a, t_flag *flag)
{
	if ((*a == '0' || *a == '+' || *a == '-' || *a == '#' || *a == ' ') &&
		flag->before_dot == 0 && flag->after_dot == 0)
	{
		if (*a == '0')
			flag->null = 1;
		if (*a == '+')
			flag->plus = 1;
		if (*a == '-')
			flag->min = 1;
		if (*a == '#')
			flag->sharp = 1;
		if (*a == ' ')
			flag->space = 1;
		return (1);
	}
	return (0);
}
