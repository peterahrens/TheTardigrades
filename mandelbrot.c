#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t* mandelbrot(float x_init, float y_init)
{
  int iter = 0;
  int iter_max = 1000;
  float radius = 0;
  float x, y;
  float radius_max = 2.0;
  uint8_t rgb[3];
  
  x = x_init;
  y = y_init;
  while (radius < radius_max && iter < iter_max)
  {
    x = x * x - y * y + x_init;
    y = 2.0 * x * y + y_init;
    iter++;
  }
  if (iter < iter_max)
  {
    *rgb = 255;
    *(rgb + 1) = 255;
    *(rgb + 2) = 255;
  }
  else
  {
    *rgb = 0;
    *(rgb + 1) = 0;
    *(rgb + 2) = 0;
  }

  return rgb;
}
