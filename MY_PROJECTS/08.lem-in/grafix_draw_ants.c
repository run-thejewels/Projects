/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafix_draw_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:37:59 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 15:45:16 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	draw_ant_img(t_pos pos, void *img, t_data *s)
{
	if (!s || !img)
		return ;
	pos.hor = OFFSET_HOR + pos.hor * s->win_size.hor / s->size.hor;
	pos.vert = OFFSET_VERT + pos.vert * s->win_size.vert / s->size.vert;
	pos.hor = pos.hor - IMG_ANT_HOR / 2;
	pos.vert = pos.vert - IMG_ANT_VERT / 2;
	mlx_put_image_to_window(s->mlx, s->win, img, pos.hor, pos.vert);
}

void		draw_ants(t_list **way_arr, t_data *s)
{
	t_list	*way;
	t_room	*room;
	short	i;

	if (!way_arr || !s)
		return ;
	i = 0;
	while (way_arr[i])
	{
		way = way_arr[i];
		while (way->next)
		{
			room = way->content;
			if (room->ant != 0)
				draw_ant_img(room->pos, s->ant_img, s);
			way = way->next;
		}
		i++;
	}
}
