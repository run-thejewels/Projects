/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karpov_globchansky_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:19:03 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/01 17:23:12 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	**make_bigger_tlist_array(t_list **src)
{
	short	size;
	short	i;
	t_list	**dst;

	if (!src)
		return (NULL);
	size = 0;
	while (src[size])
		size++;
	if (!(dst = (t_list **)malloc(sizeof(t_list *) * (size + 2))))
	{
		kill_tlist_array(src, 0);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = NULL;
	dst[i + 1] = NULL;
	free(src);
	return (dst);
}

static short	find_conflicts(t_list **way_arr, t_data *s)
{
	short	i;
	t_list	*lst;
	t_room	*room;

	if (!way_arr || !s)
		return (-1);
	i = 0;
	while (way_arr[i])
	{
		lst = way_arr[i];
		while (lst)
		{
			room = lst->content;
			if (room->room_flag == FLAG_ROOM && room->way != i + 1)
				return (1);
			lst = lst->next;
		}
		i++;
	}
	return (0);
}

static void		find_and_solve_conflicts(t_room *room, t_data *s, \
		t_list **way_arr)
{
	if (!room || !s || !way_arr)
		return ;
	while (find_conflicts(way_arr, s) > 0)
	{
		if (s->full_logs_on)
		{
			fprint_fd(s->fd, "conflict was found!!\n");
			temp_print_roomlist(room, s);
			print_all_ways(way_arr, s);
		}
		if (conflict_solver(way_arr, s) < 0)
		{
			fprint_fd(s->fd, "conflict was not solved\n");
			return ;
		}
	}
}

static void		print_new_way_status(t_list *way, t_room *room, t_data *s, \
		int way_num)
{
	if (!way || !room || !s)
		return ;
	fprint_fd(s->fd, "\n\nnew way!\n");
	temp_print_roomlist(room, s);
	print_way(way, way_num, s);
}

t_list			**karpov_globchansky(t_room *room, t_data *s)
{
	t_list	**way_arr;
	t_list	**old;
	short	i;

	if (!room || !s || !(way_arr = (t_list **)malloc(sizeof(t_list *) * 2)))
		return (NULL);
	ft_bzero(way_arr, sizeof(t_list *) * 2);
	if (!(old = cpy_way_arr(way_arr, NULL, s)))
		return (NULL);
	i = 0;
	while (can_continue(way_arr, &old, s) > 0 && \
			(way_arr[i] = dijkstra(i + 1, room, s)))
	{
		if (s->full_logs_on)
			print_new_way_status(way_arr[i], room, s, i + 1);
		if (!(way_arr = make_bigger_tlist_array(way_arr)))
			return (NULL);
		i++;
		find_and_solve_conflicts(room, s, way_arr);
	}
	kill_tlist_array(way_arr, 0);
	return (old);
}
