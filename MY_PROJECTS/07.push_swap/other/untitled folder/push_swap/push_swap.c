/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:42:21 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/24 15:54:01 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
	return (0);
}

int			ft_check(char *av, t_stack* l)
{
	int		i;
	int		v;

	i = 0;
	if (ft_strisdigit(av))
	{
		v = ft_atoi(av);
		if (v >= -2147483648 && v <= 2147483647)
		{
			while (i <= l->ia)
			{
				if (l->va[i] == v && l->va[i] != 0)
					return (ft_error());
				i++;
			}
			return (v);
		}
	}
	return (ft_error());
}

void 		maxmin(t_stack *l)
{
	if (l->ia == 0)
	{
		l->max = l->va[l->ia];
		l->min = l->va[l->ia];
	}
	if (l->max < l->va[l->ia])
		l->max = l->va[l->ia];
	if (l->min > l->va[l->ia])
		l->min = l->va[l->ia];
}

t_stack		*ft_parsing(int ac, char **av)
{
	t_stack	*l;
	int		i;

	i = 1;
	l = lstnew();
	if (ac == 2)
	{
		av =ft_strsplit(av[1], ' ');
		while (av[ac])
			ac++;
		i = 0;
	}
	while (av[i])
	{
		l->va[l->ia] = ft_check(av[i], l);
		i++;
		maxmin(l);
		l->ia++;
	}
	return (l);
}

int			main(int c, char **a)
{
	t_stack	*l;

	if (c == 1)
		return (0);
	l = ft_parsing(c, a);
	if (!ideal(l))
		alg(l);
	while(l->cs->n)
	{
		ft_printf("%s", l->cs->ct);
		l->cs = (t_com*)l->cs->n;
	}
	return (0);
}
