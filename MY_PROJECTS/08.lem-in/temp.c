/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:12:21 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/03 16:35:09 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		temp_print_link_names(t_room *room, t_data *s)
{
	int		i;
	t_room	*tmp;

	if (!room || !s || !room->link)
	{
		if (s)
			fprint_fd(s->fd, "\n");
		return ;
	}
	i = 0;
	while ((room->link)[i])
	{
		tmp = (room->link)[i];
		if (room->not_allowed[i] == 0)
			fprint_fd(s->fd, "\t|%s", tmp->name);
		else
			fprint_fd(s->fd, "\t|-%s-", tmp->name);
		i++;
	}
	fprint_fd(s->fd, "\t|\n");
}

void		temp_print_roomlist(t_room *room, t_data *s)
{
	if (!room || !s)
		return ;
	while (room->prev)
		room = room->prev;
	fprint_fd(s->fd, "===== rooms =====\n");
	while (room)
	{
		fprint_fd(s->fd, "room '%s'\tx '%d' y '%d'\t way %d\t mark %d   \t", \
				room->name, room->pos.hor, room->pos.vert, room->way, \
				room->mark);
		if (room->room_flag == FLAG_ROOM)
			fprint_fd(s->fd, "ROOM\t");
		else if (room->room_flag == FLAG_END)
			fprint_fd(s->fd, "END\t");
		else if (room->room_flag == FLAG_START)
			fprint_fd(s->fd, "START\t");
		else
			fprint_fd(s->fd, "something else");
		temp_print_link_names(room, s);
		room = room->next;
	}
	fprint_fd(s->fd, "== end of list ==\n");
}

void		print_way(t_list *lst, int way, t_data *s)
{
	t_list	*tmp;

	if (!s || !lst)
		return ;
	fprint_fd(s->fd, "=== way %d === len %d\n", way, (int)lst->content_size);
	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
		fprint_fd(s->fd, "%s - ", ((t_room *)(tmp->content))->name);
	}
	fprint_fd(s->fd, "%s\n=== end ===\n", ((t_room *)(lst->content))->name);
}

void		print_all_ways(t_list **way_arr, t_data *s)
{
	int		i;

	if (!way_arr || !s)
		return ;
	i = -1;
	fprint_fd(s->fd, "==== start print_all_ways ====\n");
	while (way_arr[++i])
		print_way(way_arr[i], i + 1, s);
	fprint_fd(s->fd, "=== end of print_all_ways ===\n");
}
