/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_last_room.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:17:35 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/09/27 19:58:05 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*cut_room_from_list(t_room *room, t_room **lst, t_data *s)
{
	t_room		*prev;
	t_room		*next;

	if (!room || !lst || !s)
		free_exit(room, s, 1, "cut_room_from_list - empty pointer");
	prev = room->prev;
	next = room->next;
	room->prev = NULL;
	room->next = NULL;
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	if (!prev && !next)
		free_exit(room, s, 1, "cut_room_from_list - to few rooms");
	if (next)
		*lst = next;
	else
		*lst = prev;
	return (room);
}

static t_room	*pullup_first_room(t_room *room, t_data *s)
{
	t_room		*lst;

	if (!room || !s)
		free_exit(room, s, 1, "pullup_first_room - empty pointer");
	while (room->next)
		room = room->next;
	while (room->prev && room->room_flag != FLAG_START)
		room = room->prev;
	if (room->room_flag != FLAG_START)
		free_exit(room, s, 1, "ERROR: first room expected");
	room = cut_room_from_list(room, &lst, s);
	while (lst->prev)
		lst = lst->prev;
	lst->prev = room;
	room->next = lst;
	return (room);
}

static t_room	*pushback_last_room(t_room *room, t_data *s)
{
	t_room		*lst;

	if (!room || !s)
		free_exit(room, s, 1, "pushback_last_room - empty pointer");
	while (room->next)
		room = room->next;
	while (room->prev && room->room_flag != FLAG_END)
		room = room->prev;
	if (room->room_flag != FLAG_END)
		free_exit(room, s, 1, "last room expected");
	room = cut_room_from_list(room, &lst, s);
	while (lst->next)
		lst = lst->next;
	lst->next = room;
	room->prev = lst;
	return (room);
}

static void		check_for_wrong_start_end_rooms(t_room *room, t_data *s)
{
	if (!room || !s)
		free_exit(room, s, 1, "check rooms - empty pointer");
	while (room->prev)
		room = room->prev;
	while (room)
	{
		if (room->prev && room->next && room->room_flag != FLAG_ROOM)
			free_exit(room, s, 1, "double start / end found");
		room = room->next;
	}
}

t_room			*get_first_last_room(t_room *room, t_data *s)
{
	if (!room || !s || (room->next == NULL && room->prev == NULL))
		free_exit(room, s, 1, "get_first_room empty pointer");
	temp_print_roomlist(room, s);
	room = pushback_last_room(room, s);
	room = pullup_first_room(room, s);
	check_for_wrong_start_end_rooms(room, s);
	temp_print_roomlist(room, s);
	return (room);
}
