/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:28:38 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/22 17:02:36 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t printer(t_flag *flag, int i)
{
	size_t	temp;

	temp = 0;
	if (flag->str)
	{
		first_flag_before(i, flag);
		if (flag->flag_5 == 's' || flag->flag_5 == 'c' || flag->flag_5 == 'S')
			fixer_str(flag);
		else
			fixer_num(flag);
		temp = ft_strlen(flag->str);
		ft_lstadd(&(flag->lst), ft_lstnew_without_copy(flag->str, temp));
	}
	return (temp);
}
