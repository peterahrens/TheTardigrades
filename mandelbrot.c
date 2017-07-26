#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "image.h"

void dump_mandelbrot(const char *file, double centerx, double centery, double lengthx, double lengthy, int pixel_countx)
{
  double pixel_size = lengthx / (double)pixel_countx;
  int pixel_county = (int)(lengthy / pixel_size);

  double *hsv = (double*)malloc(pixel_countx * pixel_county * 3 * sizeof(double));

  double minx = centerx - lengthx / 2.0;
  double maxy = centery + lengthy / 2.0;

  #pragma acc data copyout(hsv[:pixel_countx * pixel_county * 3])
  {
  #pragma acc parallel loop collapse(2)
  for (int pixely = 0; pixely < pixel_county; pixely++)
  {
    for (int pixelx = 0; pixelx < pixel_countx; pixelx++)
    {
      double x_init = minx + (pixelx * pixel_size) + pixel_size * 0.5;
      double y_init = maxy - (pixely * pixel_size) + pixel_size * 0.5;
      int i = (pixel_countx * pixely + pixelx) * 3;

      int iter_max = 10000;
      double radius_max = 1 << 18;

      double x = 0.0;
      double y = 0.0;
      double dx = 0.0;
      double dy = 0.0;
      int iter = 0;
      double radius = 0;
      while (radius < radius_max && iter < iter_max)
      {
        double x_old = x;
        double y_old = y;
        double dx_old = dx;
        double dy_old = dy;
        dx = 2.0 * (x_old * dx_old - y_old * dy_old) + 1;
        dy = 2.0 * (x_old * dy_old + y_old * dx_old);
        x = x_old * x_old - y_old * y_old + x_init;
        y = 2.0 * x_old * y_old + y_init;
        radius = sqrt(x * x + y * y);
        iter++;
      }
      double dradius = sqrt(dx * dx + dy * dy);
      double distance = log(dradius) * radius / dradius;

    }
  }
  }

  dump_hsv(file, pixel_countx, pixel_county, hsv);
  free(hsv);
}
