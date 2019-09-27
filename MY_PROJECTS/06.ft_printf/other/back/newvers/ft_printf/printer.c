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

int printer(t_flag *flag, int i)
{
	size_t	temp;

	first_flag_before(i, flag);
	if (flag->flag_5 == 's')
		fixer_str(flag);
	else
		fixer_num(flag);
	temp = ft_strlen(flag->str);
	//ft_putstr_len(flag->str, temp);
	return (temp);
}
