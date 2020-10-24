#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>

typedef struct
{
  int x;
  int y;
  int **z;
  int zoom;
  int color;
  int shift_x;
  int shift_y;
  float angle;
  int bresenham;

  void *mlx_ptr;
  void *win_ptr;
} t_dot;

void read_file(char* file_name, t_dot *data);
void bresenham(float x, float y, float x1, float y1, t_dot* data);
void draw_map(t_dot* data);

void move(int key, t_dot* data);
void zoom(int key, t_dot* data);
void angle(int key, t_dot* data);
void flag_b(int key, t_dot* data);

void get_zoom(float *x, float *y, float *x1, float *y1, int zoom);
void get_color(int z, int z1, t_dot* data);
void get_shift(float* x, float* y, float* x1, float* y1, t_dot* data);
void get_step(float x, float y, float x1, float y1, float* x_s, float* y_s);

float max_f(float a, float b);
float mod_f(float a);
void isometric(float *x, float *y, int z, float angle);


#endif
