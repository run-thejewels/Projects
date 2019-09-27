/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:11:41 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/24 16:13:39 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void        reset(t_stack* l)
{
	while (l->int_a > 0)
	{
		if (l->com_a == 'r')
		{
			rrs(l, 'a');
			l->int_a--;
		}
		if (l->com_a == 'R')
		{
			rs(l, 'a');
			l->int_a--;
			if (l->int_a == 0)
			{
				rs(l, 'a');
				l->int_a--;
			}
		}
	}
	while (l->va[0] != l->min)
	{
		if (l->com_a == 'r')
			rrs(l, 'a');
		if (l->com_a == 'R')
			rs(l, 'a');
	}
}
