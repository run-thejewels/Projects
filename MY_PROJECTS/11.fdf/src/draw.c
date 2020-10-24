#include "../include/fdf.h"

void bresenham(float x, float y, float x1, float y1, t_dot* data)
{
  float x_step;
  float y_step;
  int z;
  int z1;

  z = data->z[(int)y][(int)x];
  z1 = data->z[(int)y1][(int)x1];
  get_zoom(&x, &y, &x1, &y1, data->zoom);
  get_color(z, z1, data);
  get_shift(&x, &y, &x1, &y1, data);
  get_step(x, y, x1, y1, &x_step, &y_step);
  if(data->bresenham)
  {
    isometric(&x, &y, z, data->angle);
    isometric(&x1, &y1, z1, data->angle);
  }
  while((int)(x - x1) || (int)(y - y1))
  {
    mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
    x += x_step;
    y += y_step;
  }
}

void draw_map(t_dot* data)
{
  int x;
  int y;

  y = 0;
  while(y < data->x)
  {
    x = 0;
    while (x < data->y)
    {
      if(x < data->y - 1)
        bresenham(x, y, x + 1, y, data);
      if(y < data->x - 1)
        bresenham(x, y, x, y+ 1, data);
      x++;
    }
    y++;
  }
}
