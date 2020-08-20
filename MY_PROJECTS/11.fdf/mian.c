#include "fdf.h"

int main(int count, char** var)
{
  fdf *data;

  data = (fdf*)malloc(sizeof(fdf));
  read_file(var[1], data);
  data->mlx_ptr = mlx_init();
  data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");

  //void bresenham(float x, float y, float x1, float y1, fdf *data)
  draw(data);
//  mlx_key_hook(data->win_ptr, data_key, NULL);
  mlx_loop(data->mlx_ptr);
  return(0);
}
