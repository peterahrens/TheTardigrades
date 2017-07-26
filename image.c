#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    double r;       // ∈ [0, 1]
    double g;       // ∈ [0, 1]
    double b;       // ∈ [0, 1]
} rgb;

typedef struct {
    double h;       // ∈ [0, 360]
    double s;       // ∈ [0, 1]
    double v;       // ∈ [0, 1]
} hsv;

rgb hsv2rgb(hsv HSV)
{
    rgb RGB;
    double H = HSV.h, S = HSV.s, V = HSV.v,
            P, Q, T,
            fract;

    (H == 360.)?(H = 0.):(H /= 60.);
    fract = H - floor(H);

    P = V*(1. - S);
    Q = V*(1. - S*fract);
    T = V*(1. - S*(1. - fract));

    if      (0. <= H && H < 1.)
        RGB = (rgb){.r = V, .g = T, .b = P};
    else if (1. <= H && H < 2.)
        RGB = (rgb){.r = Q, .g = V, .b = P};
    else if (2. <= H && H < 3.)
        RGB = (rgb){.r = P, .g = V, .b = T};
    else if (3. <= H && H < 4.)
        RGB = (rgb){.r = P, .g = Q, .b = V};
    else if (4. <= H && H < 5.)
        RGB = (rgb){.r = T, .g = P, .b = V};
    else if (5. <= H && H < 6.)
        RGB = (rgb){.r = V, .g = P, .b = Q};
    else
        RGB = (rgb){.r = 0., .g = 0., .b = 0.};

    return RGB;
}

void dump_gs(const char* name, const size_t width, const size_t height, const uint8_t *data){
  char fname[strlen(name) + 5];
  strcpy(fname, name);
  strcat(fname, ".pgs");
  FILE *file = fopen(fname, "w");
  fprintf(file, "P5\n");
  fprintf(file, "%zd, %zd\n", width, height);
  fprintf(file, "255\n");
  fwrite(data, sizeof(uint8_t), width * height, file);
  fclose(file);
}

void dump_rgb(const char* name, const size_t width, const size_t height, const uint8_t *data){
  char fname[strlen(name) + 5];
  strcpy(fname, name);
  strcat(fname, ".ppm");
  FILE *file = fopen(fname, "w");
  fprintf(file, "P6\n");
  fprintf(file, "%zd, %zd\n", width, height);
  fprintf(file, "255\n");
  fwrite(data, sizeof(uint8_t), width * height * 3, file);
  fclose(file);
}

void dump_hsv(const char* name, const size_t width, const size_t height, const double *data){
  uint8_t newdata[width * height * 3];
  for(int i = 0; i < width * height; i++){
    hsv in;
    in.h = data[i * 3 + 0];
    in.s = data[i * 3 + 1];
    in.v = data[i * 3 + 2];
    rgb out = hsv2rgb(in);
    newdata[i * 3 + 0] = (uint8_t)out.r;
    newdata[i * 3 + 1] = (uint8_t)out.g;
    newdata[i * 3 + 2] = (uint8_t)out.b;
  }
  dump_rgb(name, width, height, newdata);
}
