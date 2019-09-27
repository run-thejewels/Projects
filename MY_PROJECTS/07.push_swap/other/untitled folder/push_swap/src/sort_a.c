/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:16:44 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/24 16:08:18 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		varios(int b, t_stack* l)
{
	int	c;
	int	min;
	int	k;

	c = 0;
	k = 0;
	min = l->max;
	while (c < l->ia)
	{
		if (l->va[c] > b && l->va[c] < min)
		{
			if ( l->va[c - 1] < b || (c == 0 && l->va[l->ia - 1] < b))
			{
				min = l->va[c];
				k = c;
			}
		}
		c++;
	}
	if (k > l->ia)
		return (0);
	return (k);
}

int		sort_a(int b, t_stack* l)
{
	int	i;

	i = 0;
	i = varios(b ,l);
	if (i == 0)
		l->com_a[l->in] = '0';
	else if (l->ia - i  < i && l->ia - i > 0)
	{
		i = l->ia - i;
		l->com_a[l->in] = 'R';
	}
	else
		l->com_a[l->in] = 'r';
	return (i);
}
