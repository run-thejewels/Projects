/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <kbethany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:10:40 by kbethany          #+#    #+#             */
/*   Updated: 2020/11/01 20:47:58 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	bresenham_right(t_dot a, t_dot b, t_data *data)
{
	float	x_step;
	float	y_step;

	b.x++;
	a.z = data->z[(int)a.y][(int)a.x];
	b.z = data->z[(int)b.y][(int)b.x];
	get_zoom(&a, &b, data->zoom);
	get_color(a.z, a.z, data);
	get_shift(&a, &b, data);
	get_step(&a, &b, &x_step, &y_step);
	if (data->bresenham)
	{
		isometric(&a.x, &a.y, a.z, data->angle);
		isometric(&b.x, &b.y, b.z, data->angle);
	}
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, data->color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	bresenham_down(t_dot a, t_dot b, t_data *data)
{
	float	x_step;
	float	y_step;

	b.y++;
	a.z = data->z[(int)a.y][(int)a.x];
	b.z = data->z[(int)b.y][(int)b.x];
	get_zoom(&a, &b, data->zoom);
	get_color(a.z, a.z, data);
	get_shift(&a, &b, data);
	get_step(&a, &b, &x_step, &y_step);
	if (data->bresenham)
	{
		isometric(&a.x, &a.y, a.z, data->angle);
		isometric(&b.x, &b.y, b.z, data->angle);
	}
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, data->color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	draw_map(t_data *data)
{
	t_dot start_dot;
	t_dot end_dot;

	start_dot.y = -1;
	print_menu(data);
	while (start_dot.y++ < data->x)
	{
		start_dot.x = -1;
		while (start_dot.x++ < data->y)
		{
			end_dot.x = start_dot.x;
			end_dot.y = start_dot.y;
			if (start_dot.x < data->y - 1)
				bresenham_right(start_dot, end_dot, data);
			if (start_dot.y < data->x - 1)
				bresenham_down(start_dot, end_dot, data);
		}
	}
}
