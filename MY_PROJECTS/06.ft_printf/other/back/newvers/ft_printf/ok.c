/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:53:24 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:04:32 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ok(char *str, t_flag *flag)
{
	int	num;

	num = 0;
	if (flag_begin_chek(str[num], flag))
		num++;
	if (second_flag(&str[num], flag))
		num += ft_math_numlen_long((long int)flag->before_dot);
	if (str[num] == '.')
	{
		num++;
		if (str[num] > '0' && str[num] <= '9')
		{
			flag->after_dot = ft_atoi(str + num);
			flag->after_flag = 1;
			num += ft_math_numlen_long((long int)flag->after_dot);
		}
	}
	num = size_flag(&str[num], flag);
	return (num);
}
