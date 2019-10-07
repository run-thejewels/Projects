/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:07:40 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 15:57:26 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	find_min_max_position(t_room *room, t_data *s)
{
	if (!room || !s)
		return (-1);
	while (room->prev)
		room = room->prev;
	s->min_pos.hor = room->pos.hor;
	s->max_pos.hor = room->pos.hor;
	s->min_pos.vert = room->pos.vert;
	s->max_pos.vert = room->pos.vert;
	while (room->next)
	{
		room = room->next;
		if (s->min_pos.hor > room->pos.hor)
			s->min_pos.hor = room->pos.hor;
		if (s->max_pos.hor < room->pos.hor)
			s->max_pos.hor = room->pos.hor;
		if (s->min_pos.vert > room->pos.vert)
			s->min_pos.vert = room->pos.vert;
		if (s->max_pos.vert < room->pos.vert)
			s->max_pos.vert = room->pos.vert;
	}
	return (0);
}

static int	start_calc(t_room *room, t_data *s)
{
	if (!room || !s)
		return (-1);
	if (find_min_max_position(room, s) < 0)
		return (-1);
	s->size.hor = (int)ft_absi(s->max_pos.hor - s->min_pos.hor);
	s->size.vert = (int)ft_absi(s->max_pos.vert - s->min_pos.vert);
	s->win_size.hor = WIN_SIZE_HOR - 2 * OFFSET_HOR;
	s->win_size.vert = WIN_SIZE_VERT - 2 * OFFSET_VERT;
	if (!(s->mlx = mlx_init()) || \
			!(s->win = mlx_new_window(s->mlx, \
					WIN_SIZE_HOR, WIN_SIZE_VERT, "lem-in by bsabre-c")))
		return (-1);
	return (0);
}

int			create_images(t_data *s)
{
	int		width;
	int		height;

	if (!s)
		return (-1);
	width = IMG_ROOM_HOR;
	height = IMG_ROOM_VERT;
	if (!(s->room_img = mlx_xpm_file_to_image(s->mlx, "img/room.xpm", &width, \
					&height)))
		return (-1);
	width = IMG_END_HOR;
	height = IMG_END_VERT;
	if (!(s->end_room_img = mlx_xpm_file_to_image(s->mlx, \
					"img/black_hole.xpm", &width, &height)))
		return (-1);
	width = IMG_ANT_HOR;
	height = IMG_ANT_VERT;
	if (!(s->ant_img = mlx_xpm_file_to_image(s->mlx, "img/ant.xpm", &width, \
					&height)))
		return (-1);
	return (0);
}

int			grafix(t_data *s)
{
	if (!s)
		return (-1);
	fprint_fd(s->fd, "\n\n===== GRAFIX START =====\n");
	if (start_calc(s->room, s) < 0 || create_images(s) < 0)
		return (-1);
	s->is_pause = 1;
	insert_rooms_in_way_arr(s->way_arr, s);
	insert_rooms_in_way_arr(s->way_arr, s);
	insert_rooms_in_way_arr(s->way_arr, s);
	insert_rooms_in_way_arr(s->way_arr, s);
	insert_ants(s->ant_queues, s);
	insert_ants(s->ant_queues, s);
	insert_ants(s->ant_queues, s);
	insert_ants(s->ant_queues, s);
	bzero_ant_nbrs(s->way_arr);
	draw_room_web(s->room, s);
	print_all_ways(s->way_arr, s);
	mlx_loop_hook(s->mlx, loop_hook, s);
	mlx_key_hook(s->win, key_escape, s);
	mlx_mouse_hook(s->win, mouse_pause, s);
	mlx_loop(s->mlx);
	return (0);
}
