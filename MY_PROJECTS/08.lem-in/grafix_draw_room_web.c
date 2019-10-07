/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafix_draw_room_web.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:39:50 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 15:50:23 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	bzero_all_not_allowed(t_room *room)
{
	short	i;

	if (!room)
		return ;
	while (room)
	{
		i = 0;
		while (room->link[i])
			room->not_allowed[i++] = 0;
		room = room->next;
	}
}

static void	set_not_allowed(t_room *room, t_room *ptr)
{
	short	i;

	if (!room || !ptr)
		return ;
	i = 0;
	while (room->link[i] && room->link[i] != ptr)
		i++;
	if (room->link[i] == ptr)
		room->not_allowed[i] = 1;
}

static void	draw_room_img(t_pos pos, void *img, short is_end_room, t_data *s)
{
	if (!s || !img)
		return ;
	pos.hor = OFFSET_HOR + pos.hor * s->win_size.hor / s->size.hor;
	pos.vert = OFFSET_VERT + pos.vert * s->win_size.vert / s->size.vert;
	if (!is_end_room)
	{
		pos.hor = pos.hor - IMG_ROOM_HOR / 2;
		pos.vert = pos.vert - IMG_ROOM_VERT / 2;
	}
	else
	{
		pos.hor = pos.hor - IMG_END_HOR / 2;
		pos.vert = pos.vert - IMG_END_VERT / 2;
	}
	mlx_put_image_to_window(s->mlx, s->win, img, pos.hor, pos.vert);
}

void		draw_room_web(t_room *room, t_data *s)
{
	t_room	*tmp;
	short	i;

	if (!room || !s)
		return ;
	while (room->prev)
		room = room->prev;
	bzero_all_not_allowed(room);
	while (room->next)
	{
		i = 0;
		while ((tmp = room->link[i]))
		{
			if (!room->not_allowed[i])
			{
				room->not_allowed[i] = 1;
				set_not_allowed(tmp, room);
				draw_line(room->pos, tmp->pos, 0x50, s);
			}
			draw_room_img(room->pos, s->room_img, 0, s);
			i++;
		}
		room = room->next;
	}
	draw_room_img(room->pos, s->end_room_img, 1, s);
}
