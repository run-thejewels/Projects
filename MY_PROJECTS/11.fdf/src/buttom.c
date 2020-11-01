/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <kbethany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:04:08 by kbethany          #+#    #+#             */
/*   Updated: 2020/11/01 19:09:46 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move(int key, t_data *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
}

void	zoom(int key, t_data *data)
{
	if (key == 24)
		data->zoom += 1;
	if (key == 27)
		data->zoom -= 1;
}

void	angle(int key, t_data *data)
{
	if (key == 33)
		data->angle -= 0.01;
	if (key == 30)
		data->angle += 0.01;
	if (key == 39)
		data->angle -= 0.1;
	if (key == 42)
		data->angle += 0.1;
}

void	flag_b(int key, t_data *data)
{
	if (key == 11)
	{
		if (data->bresenham)
			data->bresenham = 0;
		else
			data->bresenham = 1;
	}
}
