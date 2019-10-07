/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafix_insert_rooms.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:49:15 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 15:34:53 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	find_position(t_room *room, t_pos pos, int fract)
{
	if (!room)
		return ;
	if (room->pos.hor != pos.hor)
		room->pos.hor += (pos.hor - room->pos.hor) / fract;
	if (room->pos.vert != pos.vert)
		room->pos.vert += (pos.vert - room->pos.vert) / fract;
}

static void	insert_rooms(t_list *prev, t_list *next, t_data *s, int fract)
{
	t_room	*room;
	t_room	*rnext;
	t_room	*rprev;
	t_list	*lst;

	if (!prev || !next || !s)
		return ;
	if (!(lst = ft_lstnew_fag(NULL, 0)))
		return ;
	rprev = prev->content;
	rnext = next->content;
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return ;
	*room = *rprev;
	if (!(room->name = ft_strdup(rprev->name)))
		return ;
	find_position(room, rnext->pos, fract);
	prev->next = lst;
	lst->next = next;
	lst->content = room;
}

void		insert_rooms_in_way_arr(t_list **way_arr, t_data *s)
{
	t_list	*way;
	t_list	*next;
	short	i;

	if (!way_arr || !s)
		return ;
	i = 0;
	while (way_arr[i])
	{
		way = way_arr[i];
		while (way->next)
		{
			next = way->next;
			insert_rooms(way, next, s, 3);
			insert_rooms(way->next, next, s, 2);
			way = next;
		}
		i++;
	}
}
