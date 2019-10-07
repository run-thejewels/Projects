/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafix_make_step.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:17:00 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 15:36:29 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	shift_ants(t_list *way, size_t ant_nbr, t_data *s, short i)
{
	t_room	*room;

	if (!way || !s)
		return ;
	room = way->content;
	shift_ants(way->next, room->ant, s, i);
	if (way->next == NULL && ant_nbr)
		s->ants--;
	else
		room->ant = ant_nbr;
}

void		make_step(t_list **way_arr, t_list **ant_queues, t_data *s)
{
	short	i;
	t_list	*tmp;

	if (!way_arr || !ant_queues || !s)
		return ;
	s->steps++;
	i = -1;
	while (way_arr[++i])
	{
		if (ant_queues[i])
		{
			shift_ants(way_arr[i]->next, ant_queues[i]->content_size, s, i);
			tmp = ant_queues[i];
			ant_queues[i] = ant_queues[i]->next;
			free(tmp);
		}
		else
			shift_ants(way_arr[i], 0, s, i);
	}
}
