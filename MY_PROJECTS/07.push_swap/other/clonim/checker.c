/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:56:17 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/31 22:17:40 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	comander_omega(t_stack *l, char *str)
{
	if (!ft_strcmp(str, "pa"))
	{
		pa(l);
		return (1);
	}
	if (!ft_strcmp(str, "pb"))
	{
		pb(l);
		return (1);
	}
	if (!ft_strcmp(str, "ra"))
	{
		rr(l, 'a');
		return (1);
	}
	if (!ft_strcmp(str, "rb"))
	{
		rr(l, 'b');
		return (1);
	}
	return (0);
}

static int	comander_delta(t_stack *l, char *str)
{
	if (!ft_strcmp(str, "sa"))
	{
		ss(l, 'a');
		return (1);
	}
	if (!ft_strcmp(str, "sb"))
	{
		ss(l, 'b');
		return (1);
	}
	if (!ft_strcmp(str, "ss"))
	{
		ss(l, 's');
		return (1);
	}
	if (!ft_strcmp(str, "rr"))
	{
		rr(l, 's');
		return (1);
	}
	return (0);
}

static int	comander_alfa(t_stack *l, char *str)
{
	if (!ft_strcmp(str, "rra"))
	{
		rrs(l, 'a');
		return (1);
	}
	if (!ft_strcmp(str, "rrb"))
	{
		rrs(l, 'b');
		return (1);
	}
	if (!ft_strcmp(str, "rrr"))
	{
		rrs(l, 's');
		return (1);
	}
	return (0);
}

int			main(int c, char **v)
{
	t_stack	*l;
	char	*str;

	str = NULL;
	if (c < 2)
		return (0);
	l = parsing(c, v);
	while ((get_next_line(0, &str) == 1))
	{
		if (!comander_alfa(l, str) && !comander_delta(l, str) &&
			!comander_omega(l, str))
			return (ft_error(l));
		if (str)
			free(str);
	}
	if (ideal(l) && l->ib == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	leaker(l->cs, l);
	return (0);
}
