#include "../include/fdf.h"

void	print_menu(t_dot* data)
{
	char *menu;

	menu = "up, down, left, right: move picture";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5, 0x03fc35, menu);
	menu = "b: 3d/2d mode; +, -: zoom {, }: zoom x2";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0x03fc35, menu);
	menu = "8, 2: z-scale; 4, 6: rotation";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 35, 0x03fc35, menu);
}
