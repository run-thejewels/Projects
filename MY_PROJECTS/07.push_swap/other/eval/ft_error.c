/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:14:03 by kbethany          #+#    #+#             */
/*   Updated: 2019/09/04 13:14:20 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	leaker(t_com *c, t_stack *l)
{
	t_com	*p;

	if (c)
	{
		while (c->n)
		{
			p = c->n;
			free(c->ct);
			free(c);
			c = p;
		}
		free(c->ct);
		free(c);
	}
	if (l->v)
		display(l);
	free(l->va);
	l = NULL;
}

int		ft_error(t_stack *l)
{
	write(2, "Error\n", 6);
	l->v = 0;
	leaker(NULL, l);
	exit(1);
	return (0);
}
