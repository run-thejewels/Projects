#include "../include/fdf.h"

void get_zoom(float *x, float *y, float *x1, float *y1, int zoom)
{
  *x *= zoom;
  *x1 *= zoom;
  *y *= zoom;
  *y1 *= zoom;
}

void get_color(int z, int z1, t_dot* data)
{
  if(z || z1)
    data->color = 0xe80c0c;
  else
    data->color = 0xffffff;
}

void get_shift(float* x, float* y, float* x1, float* y1, t_dot* data)
{
  *x += data->shift_x;
  *y += data->shift_y;
  *x1 += data->shift_x;
  *y1 += data->shift_y;
}

void get_step(float x, float y, float x1, float y1, float* x_s, float* y_s)
{
  float max;

  max = max_f(mod_f(x1 - x), mod_f(y1 - y));
  *x_s = (x1 - x)/max;
  *y_s = (y1 - y)/max;
}
