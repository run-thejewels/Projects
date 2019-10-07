/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karpov_globchansky_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:56:05 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/01 17:22:07 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		*create_way_size_arr(t_list **way_arr, short size, t_data *s)
{
	int		*dst;
	short	i;

	if (!way_arr || !s)
		return (NULL);
	if (!(dst = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (way_arr[i]->content_size > (size_t)INTMAX)
			dst[i] = INTMAX;
		else
			dst[i] = way_arr[i]->content_size;
	}
	return (dst);
}

static int		count_size(int *waiting, short size, int ants, t_data *s)
{
	int		dst;
	short	i;

	if (!waiting || !s)
		return (0);
	dst = 0;
	i = 0;
	while (ants > 0)
	{
		dst++;
		i = 0;
		while (i < size)
		{
			if (waiting[i] > 1)
				(waiting[i])--;
			else
				ants--;
			i++;
		}
	}
	free(waiting);
	return (dst);
}

static int		size_of_ant_queue(t_list **way_arr, t_data *s)
{
	short	size;
	int		*waiting;

	if (!way_arr || !s)
		return (0);
	size = 0;
	while (way_arr[size])
		size++;
	if (size == 0)
		return (INTMAX);
	if (!(waiting = create_way_size_arr(way_arr, size, s)))
		return (0);
	return (count_size(waiting, size, s->ants, s));
}

int				can_continue(t_list **way_arr, t_list ***old, t_data *s)
{
	int		new_len;
	int		old_len;

	if (!way_arr || !old || !(*old) || !s)
		return (-1);
	new_len = size_of_ant_queue(way_arr, s);
	old_len = size_of_ant_queue(*old, s);
	fprint_fd(s->fd, "old len %d, new_len %d\n", (int)old_len, (int)new_len);
	if (new_len == 1)
		return (0);
	if (new_len > old_len)
	{
		fprint_fd(s->fd, "cannot continue\n");
		return (0);
	}
	if (!(*old = cpy_way_arr(way_arr, *old, s)))
		return (-1);
	fprint_fd(s->fd, "we must continue\n");
	return (1);
}
