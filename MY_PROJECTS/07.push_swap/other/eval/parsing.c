/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 21:44:16 by kbethany          #+#    #+#             */
/*   Updated: 2019/09/06 14:20:35 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int			check(char *av, t_stack *l)
{
	int			i;
	long		v;
	static char	k[10] = "2147483647";

	i = 0;
	v = 0;
	if (ft_strlen(av) == ft_strlen(k) && ft_strcmp(av, k) > 0)
		return (ft_error(l));
	else if (ft_strlen(av) > ft_strlen(k))
		return (ft_error(l));
	if (ft_strisdigit(av))
	{
		v = ft_atoi(av);
		while (i < l->ia)
		{
			if (l->va[i] == v)
				return (ft_error(l));
			i++;
		}
		return (v);
	}
	return (ft_error(l));
}

static void	maxmin(t_stack *l, char *a, int k)
{
	l->vv[l->iv] = l->va[l->ia];
	if (l->ia == 0)
	{
		l->max = l->va[l->ia];
		l->min = l->va[l->ia];
	}
	if (l->max < l->va[l->ia])
		l->max = l->va[l->ia];
	if (l->min > l->va[l->ia])
		l->min = l->va[l->ia];
	if (k)
		free(a);
	l->ia++;
	l->iv++;
}

int			bonus(char *a, t_stack *l)
{
	if (!ft_strcmp(a, "-v"))
	{
		l->v = 1;
		return (1);
	}
	return (0);
}

t_stack		*parsing(int ac, char **av)
{
	t_stack	*l;
	int		i;
	int		k;

	i = 1;
	k = 0;
	l = lstnew();
	if (ac == 2 && !bonus(av[i], l))
	{
		av = ft_strsplit(av[1], ' ');
		while (av[ac])
			ac++;
		i = 0;
		k = 1;
	}
	i += bonus(av[i], l);
	while (av[i])
	{
		l->va[l->ia] = check(av[i], l);
		maxmin(l, av[i], k);
		i++;
	}
	if (k)
		free(av);
	return (l);
}
