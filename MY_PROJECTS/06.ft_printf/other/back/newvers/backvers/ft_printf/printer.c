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
	int	temp;

	first_flag_before(i, flag);
	obertka(flag);
	temp = ft_strlen(flag->str);
	ft_putstr_len(flag->str, temp);
	return (temp);
}
