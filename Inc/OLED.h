#ifndef OLED_H_
#define OLED_H_

#include <stdint.h>
#include <stdbool.h>
#include "Image.h"

#define FB_WIDTH		128U
#define FB_HEIGHT		64U

#define FB_SIZE		(FB_WIDTH*FB_HEIGHT)/8



void set_pixel(int x,int y, bool state);
bool get_pixel(int x,int y);
void draw_bitmap(int x,int y,int width,int height,const uint8_t*bitmap);
void draw_rectangle(int x,int y, int width,int height);
void draw_text(int x, int y, int size, char *text);
#endif /* OLED_H_ */
