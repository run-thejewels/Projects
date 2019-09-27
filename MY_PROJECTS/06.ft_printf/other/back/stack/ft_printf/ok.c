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

size_t	ok(char *str, t_flag *flag, va_list *arguments)
{
	size_t	num;
	size_t temp;

	num = 0;

	while (str[num] == ' ' || str[num] == '-' || str[num] == 'j' || str[num] == 'z' ||
	str[num] == '+' || str[num] == '#' || str[num] == 'l' || str[num] == 'L' ||
	str[num] == 'h' || str[num] == '.' || str[num] == '*' ||
	(str[num] >= '0' && str[num] <= '9'))
	{
		temp = 0;
		if (flag_begin_chek(&str[num + temp], flag))
			temp++;
		if (str[num + temp] == '.')
		{
			flag->dot = 1;
			temp++;
			if (str[num + temp] > '0' && str[num + temp] <= '9')
			{
				flag->after_dot = ft_atoi(str + num + temp);
				flag->after_flag = 1;
				temp += ft_math_numlen_long((long int)flag->after_dot);
			}
			if (str[num + temp] == '*')
			{
				flag->after_dot = va_arg(*arguments, int);
				temp++;
			}
		}
		else 	if (second_flag(&str[num + temp], flag) && !flag->dot)
			temp += ft_math_numlen_long((long int)flag->before_dot);
		else if (str[num + temp] == '*' && !flag->dot)
			{
				flag->before_dot = va_arg(*arguments, int);
				temp++;
			}
		temp += size_flag(&str[num + temp], flag, temp);
		num += temp;
	}
	return (num);
}
