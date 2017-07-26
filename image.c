#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>

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
  fwrite(data, sizeof(uint8_t), width * height, file);
  fclose(file);
}

