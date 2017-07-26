#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

void mandelbrot(double centerx, double centery, double lengthx, double lengthy, int pixel_countx, 
    double* hsv)
{
  int iter = 0;
  int iter_max = 1000;
  int pixel_county;
  double radius = 0;
  double x, y, minx, maxy, pixel_size, init_x, init_y;
  double radius_max = 2.0;

  minx = centerx - lengthx / 2.0;
  maxy = centery + lengthy / 2.0;
  pixel_size = lengthx / (double)pixel_countx;
  pixel_county = (int)(lengthy / pixel_size);

  for (int pixely = 0; pixely < pixel_county; pixely++)
  {
    for (int pixelx = 0; pixelx < pixel_countx; pixelx++)
    {
      double x_init = minx + pixelx * pixel_size;
      double y_init = maxy - pixely * pixel_size;
      int i = (pixel_county * pixely + pixelx) * 3;
      
      x = x_init;
      y = y_init;
      while (radius < radius_max && iter < iter_max)
      {
        x = x * x - y * y + x_init;
        y = 2.0 * x * y + y_init;
        radius = sqrt(x * x + y * y);
        iter++;
      }
      if (iter < iter_max)
      {
//printf("true %f %f\n", (x_init, y_init));
        hsv[i] = 0.;
        hsv[i+1] = 1.;
        hsv[i+2] = 0.;
      }
      else
      {
        //printf("false %f %f\n", (x_init,y_init));
        hsv[i] = 0.;
        hsv[i+1] = 0;
        hsv[i+2] = 0;
      }

    }
  }
}
