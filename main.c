#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = 0;
  c.blue = 0;
  
  clear_screen(s);

  int x;
  int y;
  
  for (x = 0; x < XRES; x=x+4) {
    for (y = 0; y < YRES; y=y+4) {
      draw_line((x * 4) % XRES, YRES/2, x, y, s, c);
      c.red = (c.red + 2) % 256;
      c.green = (c.green + 3) % 256;
      c.blue = (c.blue + 4) % 256;
    }
  } 
  
  display(s);
  save_extension(s, "lines.png");
}  
