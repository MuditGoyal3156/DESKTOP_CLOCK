#include "OLED.h"
#include "fonts.h"
#include <string.h>

uint8_t FRAME_BUFFER[FB_SIZE]={0};

void set_pixel(int x,int y, bool state){

	int pos = FB_WIDTH*(y/8)+ x;

	if (state) {
		FRAME_BUFFER[pos] |= (1 << (y % 8));   // Turn pixel ON
	} else {
	    FRAME_BUFFER[pos] &= ~(1 << (y % 8));  // Turn pixel OFF
	}
}


void draw_bitmap(int x,int y,int width,int height,const uint8_t*bitmap){
	uint8_t chkMsk=0;
	int size = (width*height)/8;

	int OGX = x;
	int OGY = y;
	for(int i = 0;i<size;i++){
		for(int j=0;j<8;j++){
			chkMsk = 0x80 >> j;

			set_pixel(x, y, bitmap[i] & chkMsk);
			x++;
			if((x - OGX) == width){
				y++;
				x=OGX;
			}
			if((y - OGY) == height){
				return;
			}

			if(y > FB_HEIGHT){
				return;
			}
		}
	}
}


void draw_rectangle(int x,int y, int width,int height)
{
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			if(j < FB_HEIGHT){
				set_pixel(x + i, y + j, true);
			}
			if(i > FB_WIDTH){
				return;
			}
		}
	}
}

void draw_text(int x, int y, int size, char *text){
	const uint8_t* font;
	const uint8_t* drawChar;

	int runningX = x;
	int runningY = y;

	int target;

	font = CGA16;
//For wrapping text

	for(int i =0;i<strlen(text);i++){

		if(runningX + size >= FB_WIDTH){
			runningX = x;
			runningY += size;
		}
		if(runningY >= FB_HEIGHT){
			return;
		}

		target = ((size*size)/8)*(text[i] - ' ');
		drawChar = font+target;

		draw_bitmap(runningX, runningY,  size, size, drawChar);
		runningX += size;
	}
}
