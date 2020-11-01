/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <kbethany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:20:33 by kbethany          #+#    #+#             */
/*   Updated: 2020/11/01 20:28:23 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef	struct
{
	int		x;
	int		y;
	int		**z;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	angle;
	int		bresenham;
	int		menu;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

typedef	struct
{
	float	x;
	float	y;
	float	z;
}			t_dot;

void		read_file(char *file_name, t_data *data);
void		bresenham_right(t_dot a, t_dot b, t_data *data);
void		bresenham_down(t_dot a, t_dot b, t_data *data);
void		draw_map(t_data *data);

void		move(int key, t_data *data);
void		zoom(int key, t_data *data);
void		angle(int key, t_data *data);
void		flag_b(int key, t_data *data);

void		get_zoom(t_dot *a, t_dot *b, int zoom);
void		get_color(int z, int z1, t_data *data);
void		get_shift(t_dot *a, t_dot *b, t_data *data);
void		get_step(t_dot *a, t_dot *b, float *x_s, float *y_s);

float		max_f(float a, float b);
float		mod_f(float a);
void		isometric(float *x, float *y, int z, float angle);
void		ft_error(char *msg);

void		print_menu(t_data *data);

#endif
