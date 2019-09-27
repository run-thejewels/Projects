/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_flag_before.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 19:07:19 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/22 17:08:35 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	first_flag_before(long long int i, t_flag *flag)
{
	if (flag->plus && i > 0)
		flag->str = ft_strjoin_free_2("+", flag->str);
	else if (flag->space && (flag->flag_5 == 'd' || flag->flag_5 == 'i' ||
		flag->flag_5 == 'u') && (*(flag->str) != '+' || *(flag->str) != '-') && i > 0)
		flag->str = ft_strjoin_free_2(" ", flag->str);
	if (flag->dot && i == 0 && (flag->flag_5 == 'd' ||
	flag->flag_5 == 'i' || flag->flag_5 == 'o' || flag->flag_5 == 'x' ||
	flag->flag_5 == 'X'))
		flag->str = ft_strdup("");
	if (flag->sharp && i == 0)
		flag->sharp = 0;
	else if (flag->sharp && flag->flag_5 == 'o')
		flag->str = ft_strjoin_free_2("0", flag->str);
	else if (flag->sharp && (flag->flag_5 == 'x' || flag->flag_5 == 'X'))
	{
		if (flag->flag_5 == 'X')
			flag->str = ft_strjoin_free_2("0X", flag->str);
		else
			flag->str = ft_strjoin_free_2("0x", flag->str);
	}
}
