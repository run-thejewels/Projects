/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:20:43 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/31 21:53:58 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	vision(t_stack *l)
{
	t_com	*c;
	int		i;

	i = 0;
	c = l->cs;
	if (l->v)
		display(l);
	while (i < l->cline_len)
	{
		if (l->v)
		{
			comander(l, l->cs->ct);
			display_com(l, l->cs->ct);
		}
		else
			ft_printf("%s", l->cs->ct);
		l->cs = (t_com*)l->cs->n;
		i++;
	}
	leaker(c, l);
}

int			main(int c, char **a)
{
	t_stack	*l;

	if (c == 1)
		return (0);
	l = parsing(c, a);
	if (!ideal(l))
		alg(l);
	vision(l);
	return (0);
}
