#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

void dump_gs(const char* name, const size_t width, const size_t height, const uint8_t *data){
  char fname[PATH_MAX];
  strcpy(fname, name);
  strcat(fname, ".pgs");
  FILE file = open(fname, "w");
  fprintf(file, "P5\n");
  fprintf(file, "%zd, %zd\n", width, height);
  fprintf(file, "255\n");
  for(size_t i = 0; i < width * height; i++){
    uint8_t mask = 1;
    while(mask < 256){
      if (mask & data[i]){
        fprintf(file, "1");
      } else {
        fprintf(file, "0");
      }
    }
  }
  fprintf(file, "\n");
  close(fname);
}

void dump_rgb(const char* name, const size_t width, const size_t height, const uint8_t *data){
  char fname[PATH_MAX];
  strcpy(fname, name);
  strcat(fname, ".ppm");
  FILE file = open(fname, "w");
  fprintf(file, "P6\n");
  fprintf(file, "%zd, %zd\n", width, height);
  fprintf(file, "255\n");
  for(size_t i = 0; i < width * height * 3; i++){
    uint8_t mask = 1;
    while(mask < 256){
      if (mask & data[i]){
        fprintf(file, "1");
      } else {
        fprintf(file, "0");
      }
    }
  }
  fprintf(file, "\n");
  close(fname);
}


int main(int argc, char** argv){
  int radius = 16;
  int width = radius;
  int height = radius;
  data[width * height];
  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){
      data[j * width + i] = (width * width + height * height < radius * radius) * 255;
    }
  }
  dump_gs("mycoofile", width, height, data);
  return 0;
}
