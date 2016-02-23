#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  float m = (float)(y1 - y0)/(float)(x1 - x0);
  int x = x0; int y = y0; int A = y1 - y0; int B = -(x1 - x0);
  int goalX = x1; int goalY = y1;
  if (x0 > x1) {
    x = x1; y = y1; A = y0 - y1; B = -(x0 - x1);
    goalX = x0; goalY = y0;
  }
  printf("slope: %f", m);
  if (m > 0 && m <= 1) {
    int d = 2 * A + B;
    while (x <= goalX) {
      plot(s, c, x, y);
      if (d > 0) {
	y += 1;
	d += 2 * B;
      }
      x += 1;
      d += 2 * A;
    }
  } else if (m > 1) {
    int d = A + 2 * B;
    while (y <= goalY) {
      plot(s, c, x, y);
      if (d < 0) {
	x += 1;
	d += 2 * A;
      }
      y += 1;
      d += 2 * B;
    }
  }
}

