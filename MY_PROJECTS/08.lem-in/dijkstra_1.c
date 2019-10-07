/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:07:49 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/09/28 15:55:01 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*init_algorithm(t_room *room, t_data *s)
{
	t_list	*dst;

	if (!room || !s)
		free_exit(room, s, 0, "init_algorithm empty ptr");
	while (room->next)
		room = room->next;
	while (room->prev)
	{
		room->mark = 0;
		room->flag = 0;
		room->prev_room = NULL;
		room = room->prev;
	}
	room->mark = 1;
	room->flag = 1;
	dst = ft_lstnew_fag(room, 0);
	return (dst);
}

static t_room	*find_way_and_set_not_allowed(t_room *room, int way, t_data *s)
{
	int		i;
	t_room	*dst;

	if (!room || !s)
		return (NULL);
	i = 0;
	if (!(dst = room->prev_room))
		return (NULL);
	i = 0;
	while (dst->link && dst->link[i] && dst->link[i] != room)
		i++;
	dst->not_allowed[i] = 1;
	if (dst->way == 0)
		dst->way = way;
	return (dst);
}

static void		free_all_and_exit(t_list **lst, t_room *room, t_data *s, \
		char *message)
{
	if (lst && *lst)
		ft_lstdel_fag(lst);
	free_exit(room, s, 0, message);
}

static t_list	*make_way_lst(int way, t_room *room, t_data *s)
{
	t_list	*lst;
	t_list	*tmp;
	t_room	*tmp_room;

	if (!room || !s)
		free_exit(room, s, 0, "make_way_lst empty ptr");
	while (room->next)
		room = room->next;
	if (!(lst = ft_lstnew_fag(room, 0)))
		free_exit(room, s, 0, "malloc error");
	while (room && room->room_flag != FLAG_START)
	{
		if (!(tmp_room = find_way_and_set_not_allowed(room, way, s)))
			free_all_and_exit(&lst, room, s, "make_way_lst empty ptr");
		room = tmp_room;
		if (!(tmp = ft_lstnew_fag(room, lst->content_size + 1)))
			free_all_and_exit(&lst, room, s, "make_way_lst malloc error");
		tmp->next = lst;
		lst = tmp;
	}
	((t_room *)(lst->content))->way = 0;
	return (lst);
}

t_list			*dijkstra(int way, t_room *room, t_data *s)
{
	t_list	*queue;

	if (!room || !s)
		free_exit(room, s, 0, "dijkstra empty ptr");
	queue = init_algorithm(room, s);
	while (queue)
	{
		if (mark_links_till_end(queue, room, s))
			break ;
		queue = queue_kill_go_next(queue, room, s);
	}
	if (!queue)
		return (NULL);
	ft_lstdel_fag(&queue);
	return (make_way_lst(way, room, s));
}
