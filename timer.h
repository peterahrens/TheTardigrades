#ifndef TIMER_H
#include <sys/time.h>
double time (void) {
  struct timeval t;
  gettimeofday(&t, NULL);
  return 1.0*t.tv_sec + 1.0e-6*t.tv_usec;
}
#define TIMER_H
#endif
