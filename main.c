#include <stdio.h>
#include <math.h>
#include "mandelbrot.h"
#include <stdint.h>
#include "image.h"

#define init_centerx -0.75
#define init_centery 0.0
#define init_lengthx 2.75
#define init_lengthy 2.0
#define init_pixelcountx 8192


uint8_t* gen_image(float centerx, float centery, float lengthx, float lengthy, int pixel_countx)
{
  float minx, maxy, pixel_size, x, y;
  int pixel_county, pixelx, pixely, i;
  uint8_t* pixels;
  uint8_t* rgb;
  minx = centerx - lengthx / 2.0;
  maxy = centery + lengthy / 2.0;
  pixel_size = lengthx / (float)pixel_countx;
  pixel_county = (int)(lengthy / pixel_size);
  pixels = (uint8_t*) malloc(3 * pixel_countx * pixel_county * sizeof(uint8_t));
  if (!pixels) {
    exit(1);
  }

  for (pixely = 0; pixely < pixel_county; pixely++)
  {
    for (pixelx = 0; pixelx < pixel_countx; pixelx++)
    {
      x = minx + pixelx * pixel_size;
      y = maxy - pixely * pixel_size;
      i = (pixel_county * pixely + pixelx) * 3;
      rgb = mandelbrot(x,y);
      pixels[i] = *rgb;
      pixels[i + 1] = *(rgb + 1);
      pixels[i + 2] = *(rgb + 2);
    }
  }
  return pixels;
}

int main(int argc, char** argv) {
  uint8_t* image;
  int init_pixelcounty;
  float pixel_size;
  image = gen_image(init_centerx, init_centery, init_lengthx, init_lengthy, init_pixelcountx);
  pixel_size = init_lengthx / (float)init_pixelcountx;
  init_pixelcounty = (int)(init_lengthy / pixel_size);
  dump_rgb("file", init_pixelcountx, init_pixelcounty, image);
}
