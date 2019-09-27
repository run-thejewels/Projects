/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:24:08 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:18:51 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	second_flag(char *a, t_flag *flag)
{
	if (*a > '0' && *a <= '9' && flag->after_dot == 0 &&
		flag->before_dot == 0 && flag->flag_5 == 0 &&
		flag->l == 0 && flag->ll == 0 && flag->hh == 0 &&
		flag->h == 0)
	{
		flag->before_flag = 1;
		flag->before_dot = ft_atoi(a);
		return (1);
	}
	return (0);
}
