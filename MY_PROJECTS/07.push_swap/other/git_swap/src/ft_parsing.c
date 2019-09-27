/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:58:05 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/30 11:40:02 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** We don't wan't the same number twice. So let's compare my new one with those
** already in the list. If it's okay, I return the int value.
*/

int				ft_isunique(t_plst *list, int v)
{
	t_node		*tmp;
	int			count;

	tmp = list->head;
	count = 0;
	if (tmp)
	{
		while (tmp)
		{
			if (v == tmp->v)
				ft_error();
			tmp = tmp->next;
		}
	}
	return (v);
}

/*
** I'm sure this is a digit but does it fit into an int value?
*/

int				ft_isint(t_plst *list, char *av)
{
	long		v;

	v = ft_atoi(av);
	return (IS_INT(v) ? ft_isunique(list, (int)v) : ft_error());
}

/*
** If my arg is digit I continue, otherwise... error.
*/

int				ft_check(t_plst *list, char *av)
{
	return (ft_strisdigit(av) ? ft_isint(list, av) : ft_error());
}

/*
** Here we check if we have some bonuses flags.
*/

int				ft_checkbonus(char **av, int *bonus)
{
	int			i;

	i = 0;
	if (ft_strcmp(av[1], "-v") == 0)
	{
		*bonus = 1;
		if (av[2])
			i = 1;
	}
	else if (ft_strcmp(av[1], "-c") == 0)
	{
		*bonus = 2;
		if (av[2])
			i = 1;
	}
	return (i);
}

/*
** We parse and check at the same time. What else?
*/

t_plst			*ft_parsing(int ac, char **av, int *bonus)
{
	t_plst		*la;
	int			v;
	int			i;

	la = ft_pslstnew();
	i = 1 + ft_checkbonus(av, bonus);
	while (i < ac)
	{
		v = ft_check(la, av[i]);
		la = ft_lstappend(la, v);
		i++;
	}
	return (la);
}
