#include "../include/fdf.h"

int deal_key(int key, t_dot *data)
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

void defolt_params(t_dot *data)
{
  data->zoom = 40;
  data->angle = 0.8;
  data->shift_x = 400;
  data->shift_y = 250;
  data->mlx_ptr = mlx_init();
  data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
}

int main(int argc, char **argv)
{
  t_dot *data;

  if (argc != 2)
  {
    ft_printf("usage: ./fdf map.fdf");
    return (0);
  }
  data = (t_dot*)malloc(sizeof(t_dot));
  defolt_params(data);
  read_file(argv[1], data);
  draw_map(data);
  mlx_key_hook(data->win_ptr, deal_key, data);
  mlx_loop(data->mlx_ptr);
  return (0);
}
