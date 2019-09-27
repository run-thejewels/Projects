/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:30:29 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/24 18:58:55 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Be careful: each functions return 0 if it's okay, otherwise it returns
** how many errors we encounter.
*/

int			ft_issortasc(t_plst *l)
{
	t_node	*tmp;
	int		index;

	tmp = l->head;
	index = 0;
	while (tmp->next != NULL)
	{
		if (tmp->v > tmp->next->v)
			index++;
		tmp = tmp->next;
	}
	return (index);
}

int			ft_issortdes(t_plst *l)
{
	t_node	*tmp;
	int		index;

	tmp = l->head;
	index = 0;
	while (tmp->next != NULL)
	{
		if (tmp->v < tmp->next->v)
			index++;
		tmp = tmp->next;
	}
	return (index);
}
