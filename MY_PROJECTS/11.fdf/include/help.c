#include "../include/fdf.h"

float max_f(float a, float b)
{
  if(a > b)
    return (a);
  else
    return (b);
}

float mod_f(float a)
{
  if(a < 0)
    a *= -1;
  return (a);
}

void isometric(float *x, float *y, int z, float angle)
{
  *x = (*x - *y) * cos(angle);
  *y = (*x + *y) * sin(angle) - z;
}
