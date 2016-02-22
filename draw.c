#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  printf("y0: %d\n", y0);
  printf("y1: %d\n", y1);
  printf("x0: %d\n", x0);
  printf("x1: %d\n", x1);
  
  float m = (y1 - y0)/(x1 - x0);
  printf("slope: %f\n", m);
  int x = x0; int y = y0;
  if (m > 0 && m < 1) {
    int A = y1 - y0; int B = -(x1 - x0); int d = 2 * A + B;
    while (x <= x1) {
      plot(s, c, x, y);
      if (d > 0) {
	y += 1;
	d += 2 * B;
      }
      x += 1;
      d += 2 * A;
    }
  }
}

