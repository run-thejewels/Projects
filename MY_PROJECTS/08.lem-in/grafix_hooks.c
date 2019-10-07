/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafix_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:23:36 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 15:58:51 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	escape_function(t_data *s)
{
	mlx_destroy_image(s->mlx, s->room_img);
	mlx_destroy_image(s->mlx, s->end_room_img);
	mlx_destroy_image(s->mlx, s->ant_img);
	mlx_destroy_window(s->mlx, s->win);
	s->steps = s->steps / 81;
	close_all(s->ant_queues, s->way_arr, s->room, s);
	exit(0);
}

int		key_escape(int key, t_data *s)
{
	if (!s)
		return (-1);
	if (key == ESCAPE)
		exit(0);
	return (0);
}

int		mouse_pause(int param, int x, int y, t_data *s)
{
	if (!s || (!param && !x && !y))
		return (-1);
	if (s->is_pause == 1 && s->is_end == 1)
		escape_function(s);
	if (s->is_pause == 0)
		s->is_pause = 1;
	else
		s->is_pause = 0;
	return (0);
}

void	print_ant_queues2(t_list **ant_queues)
{
	t_list	*queue;
	short	i;

	if (!ant_queues)
		return ;
	i = 0;
	fprint("---\n");
	while (ant_queues[i])
	{
		queue = ant_queues[i];
		while (queue)
		{
			fprint("%d ", (int)queue->content_size);
			queue = queue->next;
		}
		i++;
		fprint("\n");
	}
}

int		loop_hook(t_data *s)
{
	if (!s)
		return (-1);
	if (s->is_end == 1)
		return (0);
	if (!s->is_pause)
	{
		if (s->count < 10)
		{
			s->count++;
			return (0);
		}
		s->count = 0;
		make_step(s->way_arr, s->ant_queues, s);
		mlx_clear_window(s->mlx, s->win);
		draw_room_web(s->room, s);
		draw_ants(s->way_arr, s);
		if (s->ants < 1)
			s->is_end = 1;
	}
	return (0);
}
