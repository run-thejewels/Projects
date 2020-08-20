#include "fdf.h"

float ya_hudognik(float x, float y)
{
  return ((x - y) * cos(0.8));
}

float ya_tak_vigu(float x, float y, int z)
{
  return ((x + y) * sin(0.8) - z);
}
