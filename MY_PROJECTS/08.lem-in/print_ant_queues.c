/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant_queues.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:46:05 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 16:20:15 by bsabre-c         ###   ########.fr       */
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
	if (ant_nbr > 0)
		fprint("L%d-%s ", (int)ant_nbr, room->name);
	if (way->next == NULL && ant_nbr)
		s->ants--;
	else
		room->ant = ant_nbr;
}

void		temp_print_ant_queues(t_list **ant_queues, t_data *s)
{
	short	i;
	t_list	*queue;

	if (!s || !ant_queues || !s->full_logs_on)
		return ;
	i = 0;
	while (ant_queues[i])
	{
		queue = ant_queues[i];
		while (queue)
		{
			fprint_fd(s->fd, "%d ", (int)queue->content_size);
			queue = queue->next;
		}
		i++;
		fprint_fd(s->fd, "\n");
	}
}

void		bzero_ant_nbrs(t_list **way_arr)
{
	t_list	*way;
	t_room	*room;
	short	i;

	if (!way_arr)
		return ;
	i = 0;
	while (way_arr[i])
	{
		way = way_arr[i];
		while (way)
		{
			room = way->content;
			room->ant = 0;
			way = way->next;
		}
		i++;
	}
}

void		print_ant_queues_(t_list **way_arr, t_list **ant_queues, t_data *s)
{
	short	i;
	t_list	*tmp;

	if (!way_arr || !ant_queues || !s)
		return ;
	temp_print_ant_queues(ant_queues, s);
	bzero_ant_nbrs(way_arr);
	while (s->ants > 0)
	{
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
		ft_putchar('\n');
	}
}

void		print_ant_queues(t_list **way_arr, t_list **ant_queues, t_data *s)
{
	t_list	*way;
	t_room	*room;

	if (!way_arr || !ant_queues || !s || !way_arr[0])
		return ;
	way = way_arr[0];
	if (way->content_size == 1)
	{
		room = s->room;
		while (room->next)
			room = room->next;
		teleport_ants(room, s);
	}
	else
		print_ant_queues_(way_arr, ant_queues, s);
}
