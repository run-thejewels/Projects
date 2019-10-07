/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_linkage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:44:51 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 17:13:19 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*find_room(t_room *lst, char *name, t_data *s)
{
	t_room		*room;

	if (!lst || !name || !s)
		return (NULL);
	room = lst;
	while (room->prev && ft_strcmp(name, room->name))
		room = room->prev;
	if (!ft_strcmp(room->name, name))
		return (room);
	room = lst;
	while (room->next && ft_strcmp(name, room->name))
		room = room->next;
	if (!ft_strcmp(room->name, name))
		return (room);
	return (NULL);
}

static int		link_isnt_exists(t_room *room1, t_room *room2, t_data *s)
{
	int			i;

	if (!room1 || !room2 || !s)
		return (-1);
	i = 0;
	while (room1->link && room1->link[i])
	{
		if (!ft_strcmp(room1->link[i]->name, room2->name))
			return (0);
		i++;
	}
	i = 0;
	while (room2->link && room2->link[i])
	{
		if (!ft_strcmp(room2->link[i]->name, room1->name))
			return (0);
		i++;
	}
	return (1);
}

static void		make_not_allowed_arrays(t_room *room, t_data *s)
{
	int			i;

	if (!room || !s)
		return ;
	while (room->prev)
		room = room->prev;
	while (room)
	{
		i = 0;
		if (!(room->link))
			free_exit(room, s, 0, "one or more rooms has no links");
		while (room->link[i])
			i++;
		room->not_allowed = (short *)malloc(sizeof(short) * (i + 1));
		ft_bzero(room->not_allowed, sizeof(short) * (i + 1));
		room = room->next;
	}
}

static void		link_and_free(t_room *room1, t_room *room2, char **arr,
		t_data *s)
{
	if (!room1 || !room2 || !s || !arr)
		return ;
	if (s->full_logs_on)
		fprint_fd(s->fd, "room %s links room %s", room1->name, room2->name);
	if (link_isnt_exists(room1, room2, s) > 0)
	{
		room1->link = make_bigger_array_and_fill(room1->link, room2);
		room2->link = make_bigger_array_and_fill(room2->link, room1);
	}
	ft_strdel(&(s->line));
	ft_strdel(&(arr[0]));
	ft_strdel(&(arr[1]));
	free(arr);
}

void			make_linkage(t_room *lst, t_data *s)
{
	char		**arr;
	t_room		*room1;
	t_room		*room2;

	if (!lst || !s)
		free_exit(lst, s, 1, "make_linkage empty pointer");
	if (!s->line || s->line[0] == 'L')
		free_exit(lst, s, 1, "line dont exists or first letter is 'L'");
	while (1)
	{
		if (check_line(lst, s))
		{
			if (!(arr = ft_strsplit(s->line, '-')) || count_words(arr) != 2)
				free_exit(lst, s, 1, "make_linkage - invalid line");
			if (!(room1 = find_room(lst, arr[0], s)) || \
						!(room2 = find_room(lst, arr[1], s)) || room1 == room2)
				free_exit(lst, s, 1, "make linkage - invalid room");
			link_and_free(room1, room2, arr, s);
		}
		else
			ft_strdel(&(s->line));
		if (gnl(0, &(s->line)) == 0)
			break ;
	}
	make_not_allowed_arrays(lst, s);
}
