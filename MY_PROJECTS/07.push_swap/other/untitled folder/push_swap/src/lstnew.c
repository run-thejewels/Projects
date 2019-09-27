/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:48:51 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/24 16:07:52 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack		*lstnew(void)
{
	t_stack	*l;

	if (!(l = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	if (l != NULL)
	{
		l->va[0] = 0;
		l->vb[0] = 0;
		l->ia = 0;
		l->ib = 0;
		l->max = 0;
		l->min = 0;
		l->in = 0;
		l->com_a = 0;
		l->com_b = 0;
		l->ce = NULL;
		l->cs = NULL;
		l->v = 0;
	}
	return (l);
}
