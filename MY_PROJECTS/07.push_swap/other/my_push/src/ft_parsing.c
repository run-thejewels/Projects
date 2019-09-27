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
	uintmax_t		v;

	v = ft_atoi(av);
	if (IS_INT(v))
		return (ft_isunique(list, (int)v));
	else
		return (ft_error());
}

int				ft_check(t_plst *list, char *av)
{
	if (ft_strisdigit(av))
		return (ft_isint(list, av));
	else
		return (ft_error());
}

/*
** We parse and check at the same time. What else?
*/

t_plst			*ft_parsing(int ac, char **av)
{
	t_plst		*la;
	int			v;
	int 		i;

	i = 1;
	la = ft_pslstnew();
	while (i < ac)
	{
		v = ft_check(la, av[i]);
		la = ft_lstappend(la, v);
		i++;
	}
	return (la);
}
