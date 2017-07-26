#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

void mandelbrot(double centerx, double centery, double lengthx, double lengthy, int pixel_countx, 
    double* hsv)
{
  double pixel_size = lengthx / (double)pixel_countx;
  int pixel_county = (int)(lengthy / pixel_size);

  double minx = centerx - lengthx / 2.0;
  double maxy = centery + lengthy / 2.0;

  for (int pixely = 0; pixely < pixel_county; pixely++)
  {
    for (int pixelx = 0; pixelx < pixel_countx; pixelx++)
    {
      double x_init = minx + (pixelx * pixel_size) + pixel_size * 0.5;
      double y_init = maxy - (pixely * pixel_size) + pixel_size * 0.5;
      int i = (pixel_countx * pixely + pixelx) * 3;

      int iter_max = 1000;
      double radius_max = 2.0;

      double x = x_init;
      double y = y_init;
      int iter = 0;
      double radius = 0;
      while (radius < radius_max && iter < iter_max)
      {
        double x_old = x;
        double y_old = y;
        x = x_old * x_old - y_old * y_old + x_init;
        y = 2.0 * x_old * y_old + y_init;
        radius = sqrt(x * x + y * y);
        iter++;
      }
      if (iter < iter_max)
      {
        printf("true %f %f\n", x_init, y_init);
        hsv[i] = 0.;
        hsv[i+1] = 1.;
        hsv[i+2] = 0.;
      }
      else
      {
        printf("false %f %f\n", x_init,y_init);
        hsv[i] = 0.;
        hsv[i+1] = 0;
        hsv[i+2] = 100.;
      }

    }
  }
}
