/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_ant_queue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:57:09 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/02 14:54:00 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_ant_in_queue(t_list **ant_queues, size_t ant_nbr, short i)
{
	t_list	*lst;

	if (!ant_queues)
		return ;
	if (ant_queues[i] == NULL)
		ant_queues[i] = ft_lstnew_fag(NULL, (size_t)ant_nbr);
	else
	{
		lst = ft_lstnew_fag(NULL, (size_t)ant_nbr);
		lst->next = ant_queues[i];
		ant_queues[i] = lst;
	}
}

static void		fill_ant_queues(t_list **ant_queues, short *waiting, \
		int ants, short size)
{
	short	i;

	if (!ant_queues || !waiting)
		return ;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (ants <= 0)
				return ;
			if (waiting[i] > 1)
				waiting[i]--;
			else
				add_ant_in_queue(ant_queues, ants--, i);
			i++;
		}
	}
}

static t_list	**create_ant_queues_array(short size)
{
	t_list	**dst;
	short	i;

	if (size < 1 || size == 32767)
		return (NULL);
	if (!(dst = (t_list **)malloc(sizeof(t_list *) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i <= size)
		dst[i] = NULL;
	return (dst);
}

static short	*create_ant_waiting_queue(t_list **way_arr, t_data *s, \
		short size)
{
	short	*dst;
	short	i;

	if (!way_arr || !s)
		return (NULL);
	if (!(dst = (short *)malloc(sizeof(short) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		dst[i] = (short)(way_arr[i]->content_size);
	return (dst);
}

t_list			**prepare_ant_queues(t_list **way_arr, t_data *s)
{
	t_list	**ant_queues;
	short	*waiting;
	short	size;

	if (!way_arr || !s)
		return (NULL);
	size = 0;
	while (way_arr[size])
		size++;
	if (!(waiting = create_ant_waiting_queue(way_arr, s, size)))
		return (NULL);
	if (!(ant_queues = create_ant_queues_array(size)))
	{
		free(waiting);
		return (NULL);
	}
	fill_ant_queues(ant_queues, waiting, s->ants, size);
	free(waiting);
	return (ant_queues);
}
