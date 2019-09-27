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
//	ft_putstr("ha1!\n");
	temp = 0;
	first_flag_before(i, flag);
	if (flag->flag_5 == 's')
		fixer_str(flag);
	else
		fixer_num(flag);
	//ft_putstr("ha2!\n");
	// if(!(flag->str))
	temp = ft_strlen(flag->str);
//	ft_putnbr(temp);
	//	ft_putstr("\n");
	ft_lstadd(&(flag->lst), ft_lstnew_without_copy(flag->str, temp));
	//ft_putstr_len(flag->str, temp);
//	ft_putstr("ha3!\n");
	return (temp); 
}
