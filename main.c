#include <stdio.h>
#include "timer.h"
#include "mandelbrot.h"

#define init_centerx -0.75
#define init_centery 0.0
#define init_lengthx 2.75
#define init_lengthy 2.0
#define init_pixelcountx 100

int main(int argc, char** argv) {
  double elapsed = -time();
  dump_mandelbrot("thesuperfractalyo", init_centerx, init_centery, init_lengthx, init_lengthy, init_pixelcountx);
  elapsed += time();
  printf("elapsed time %g\n", elapsed);
}
