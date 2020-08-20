#ifndef FDF_H
# define FDF_H

#include "ft_printf/libft/includes/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>

typedef struct
{
  int x;
  int y;
  int **z;
  int zoom;
  int color;
  int x_shift;
  int y_shift;

  void *mlx_ptr;
  void *win_ptr;
} fdf;

void  read_file(char* f_name, fdf* data);
int	x_count(char *str);
float max_f(float a, float b);
void bresenham(float x, float y, float x1, float y1, fdf *data);
void draw(fdf *data);
float ya_hudognik(float x, float y);
float ya_tak_vigu(float x, float y, int z);

#endif
