#include <stdint.h>

void dump_gs(const char* name, const size_t width, const size_t height, const uint8_t *data);
void dump_rgb(const char* name, const size_t width, const size_t height, const uint8_t *data);
void dump_hsv(const char* name, const size_t width, const size_t height, const double *data);
