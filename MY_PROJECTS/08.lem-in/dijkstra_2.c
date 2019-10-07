/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:45:30 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/09/29 13:57:45 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	can_go_here(t_room *room, int i, t_data *s)
{
	if (!room || !(room->link) || !(room->link[i]) || !s)
		return (0);
	if ((room->link[i]->mark == 0 || room->link[i]->mark > room->mark) && \
			room->not_allowed[i] == 0)
	{
		if (room->link[i]->way == room->way || !(room->prev_room) || \
				(room->prev_room && room->prev_room->way == room->way))
		{
			if (s->full_logs_on)
				fprint_fd(s->fd, "room %s can go to %s\n", \
						room->name, room->link[i]->name);
			return (1);
		}
	}
	if (s->full_logs_on)
		fprint_fd(s->fd, "room %s cannot go to %s\n", \
				room->name, room->link[i]->name);
	return (0);
}

int			mark_links_till_end(t_list *queue, t_room *room_lst, t_data *s)
{
	int		i;
	t_room	*room;

	if (!queue || !room_lst || !s)
	{
		ft_lstdel_fag(&queue);
		free_exit(room_lst, s, 0, "mark_links_till_end empty ptr");
	}
	i = 0;
	room = queue->content;
	while (room->link[i])
	{
		if (can_go_here(room, i, s))
		{
			room->link[i]->prev_room = room;
			queue_push_back(queue, room->link[i], s);
			room->link[i]->mark = room->mark + 1;
		}
		if (room->link[i] && room->link[i]->room_flag == FLAG_END && \
				room->link[i]->mark == room->mark + 1)
			return (1);
		i++;
	}
	room->flag = 1;
	return (0);
}
