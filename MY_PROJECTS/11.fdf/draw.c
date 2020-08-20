#include "fdf.h"

void bresenham(float x, float y, float x1, float y1, fdf *data)
{
  float x_step;
  float y_step;
  float max;
  int z;
  int z1;

  x *= data->zoom;
  y *= data->zoom;

  x_step = x1 - x;
  y_step = y1 - y;

  z = data->z[(int)y][(int)x];
  z1 = data->z[(int)y1][(int)x1];

  data->color = (z || z1) ? 0xe80c0c : 0xffffff;

  x = ya_hudognik(x, y);
  x1 = ya_hudognik(x1, y1);
  y = ya_tak_vigu(x, y, data->z[(int)y][(int)x]);
  y1 = ya_tak_vigu(x1, y1, data->z[(int)y1][(int)x1]);

  max = max_f(x_step, y_step);
  x_step /= max;
  y_step /= max;
  while ((int)(x - x1) || (int)(y - y1))
  {
    mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
    x += x_step;
    y += y_step;
  }
}

void draw(fdf *data)
{
  int x;
  int y;

  y = 0;
  while (y < data->y)
  {
    x = 0;
    while (x < data->x)
    {
      if (x + 1 != data->x)
        bresenham(x, y, x + 1, y, data);
      if (y + 1 != data->y)
      bresenham(x, y, x, y + 1, data);
      x++;
    }
    y++;
  }
}
