/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_1_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:55:01 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:05:22 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	only_1_flag(t_flag *flag)
{
	if (flag->l > 1 || flag->ll > 1 || flag->h > 1 ||
		flag->hh > 1 || flag->L > 1)
		return (0);
	if (flag->null && (flag->flag_5 == 's' || flag->flag_5 == 'c' ||
								flag->flag_5 == 'p'))
		return (0);
	if (flag->plus && (flag->flag_5 == 's' || flag->flag_5 == 'c' ||
								flag->flag_5 == 'p'))
		return (0);
	if (flag->space && !(flag->flag_5 == 'd' || flag->flag_5 == 'i' ||
								flag->flag_5 == 'u'))
		return (0);
	if (flag->sharp && !(flag->flag_5 == 'o' || flag->flag_5 == 'x' ||
								flag->flag_5 == 'X'))
		return (0);
	if (flag->l && (flag->flag_5 == 's' || flag->flag_5 == 'c' ||
					flag->flag_5 == 'p'))
		return (0);
	if ((flag->hh || flag->h || flag->ll) &&
		(flag->flag_5 == 'f' || flag->flag_5 == 's' ||
		flag->flag_5 == 'c' || flag->flag_5 == 'p'))
		return (0);
	if (flag->L && !(flag->flag_5 == 'f'))
		return (0);
	if (flag->after_dot && (flag->flag_5 == 'c' || flag->flag_5 == 'p'))
		return (0);
	return (1);
}
