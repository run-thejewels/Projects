/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:26:38 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 17:05:40 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_need_to_add_room(t_room *room, t_data *s, short *room_flag)
{
	if (!s || !(s->line) || !room_flag)
		return (-1);
	if ((s->line)[0] == '#')
	{
		if (*room_flag != FLAG_ROOM && (!ft_strcmp(s->line, "##start") || \
				!ft_strcmp(s->line, "##end")))
			free_exit(room, s, 1, "double start / end commit!");
		if (!ft_strcmp(s->line, "##start"))
			*room_flag = FLAG_START;
		else if (!ft_strcmp(s->line, "##end"))
			*room_flag = FLAG_END;
		ft_strdel(&(s->line));
		return (0);
	}
	return (1);
}

static t_room	*add_room(t_room *room, t_data *s, short *room_flag)
{
	t_room		*tmp;

	if (!s)
		free_exit(room, s, 1, "add_room empty pointer");
	if (!(tmp = new_room(&(s->line), *room_flag)))
		free_exit(room, s, 1, "add_room empty pointer");
	*room_flag = FLAG_ROOM;
	fprint_fd(s->fd, "room was created. Name '%s' x '%d' y '%d'\n", \
			tmp->name, tmp->pos.hor, tmp->pos.vert);
	if (!room)
		return (tmp);
	while (room->next)
		room = room->next;
	room->next = tmp;
	tmp->prev = room;
	return (tmp);
}

static void		check_names_overlap(t_room *room, short room_flag, t_data *s)
{
	t_room		*prev;

	if (!room || !s)
		free_exit(room, s, 1, "check_names empty pointer");
	if (room_flag != FLAG_ROOM)
		free_exit(room, s, 1, "check_names start / end commit before linkage");
	while (room->next)
		room = room->next;
	while (room->prev)
	{
		prev = room->prev;
		while (prev)
		{
			if (!ft_strcmp(room->name, prev->name))
				free_exit(room, s, 1, \
						"check_names_overlap - two rooms has same name");
			if (room->pos.hor == prev->pos.hor && room->pos.vert == \
					prev->pos.vert)
				free_exit(room, s, 1, "check_names_overlap - coord overlap");
			prev = prev->prev;
		}
		room = room->prev;
	}
}

t_room			*read_rooms(t_data *s)
{
	t_room		*room;
	short		is_room_flag;
	short		room_flag;

	if (!s)
		free_exit(NULL, s, 1, "read_rooms empty pointer");
	is_room_flag = 1;
	room_flag = FLAG_ROOM;
	room = NULL;
	while (is_room_flag)
	{
		if (gnl(0, &(s->line)) < 1 || \
				ft_strchr(s->line, (int)'-') || (s->line)[0] == 'L')
			is_room_flag = 0;
		else
		{
			if (is_need_to_add_room(room, s, &room_flag) == 1)
			{
				if (!(room = add_room(room, s, &room_flag)))
					free_exit(room, s, 1, "read_rooms empty pointer");
			}
		}
	}
	check_names_overlap(room, room_flag, s);
	return (get_first_last_room(room, s));
}
