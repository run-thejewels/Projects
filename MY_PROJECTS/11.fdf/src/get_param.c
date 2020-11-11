/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <kbethany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:11:28 by kbethany          #+#    #+#             */
/*   Updated: 2020/11/01 20:45:21 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	get_zoom(t_dot *a, t_dot *b, int zoom)
{
	a->x *= zoom;
	b->x *= zoom;
	a->y *= zoom;
	b->y *= zoom;
}

void	get_color(int z, int z1, t_data *data)
{
	if (z || z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

void	get_shift(t_dot *a, t_dot *b, t_data *data)
{
	a->x += data->shift_x;
	b->y += data->shift_y;
	a->x += data->shift_x;
	b->y += data->shift_y;
}

void	get_step(t_dot a, t_dot b, float *x_s, float *y_s)
{
	float	max;

	max = max_f(mod_f(b.x - a.x), mod_f(b.y - a.y));
	*x_s = (b.x - a.x) / max;
	*y_s = (b.y - a.y) / max;
}
