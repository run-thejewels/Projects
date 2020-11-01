/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <kbethany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:13:00 by kbethany          #+#    #+#             */
/*   Updated: 2020/11/01 20:43:08 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	defolt_params(t_data *data)
{
	data->zoom = 40;
	data->angle = 0.8;
	data->shift_x = 400;
	data->shift_y = 250;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
}

int		deal_key(int key, t_data *data)
{
	ft_printf("%d\n", key);
	move(key, data);
	zoom(key, data);
	angle(key, data);
	flag_b(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_error("usage: ./fdf map.fdf");
	data = (t_data*)malloc(sizeof(t_data));
	defolt_params(data);
	read_file(argv[1], data);
	draw_map(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
