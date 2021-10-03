#include "lodepng.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
char *inFilename, *outFilename;;
unsigned error;
unsigned char* image;
unsigned width, height;
unsigned x, y;
unsigned char r, g, b;
unsigned maxHeight, maxWidth;
unsigned pDone;
image = (char*) malloc(1000);
	
	inFilename = argv[1];
	outFilename = argv[2];
	//decodes the original image
	error = lodepng_decode32_file(&image, &width, &height, inFilename);
	if(error){
		printf("error %u: %s\n", error, lodepng_error_text(error));
		return 0;
	}
	maxHeight = height - 1;
	maxWidth = width - 1;
//cycles through all the pixels
	for(y = 0; y < height; y++)
		for(x = 0; x < width; x++)
		{
		pDone = 0;
			// assigns r 
			r = image[4 * width * y + 4 * x + 0];
			g = image[4 * width * y + 4 * x + 1];
			b = image[4 * width * y + 4 * x + 2];
//if top left corner of image
			if (y == 0 && x == 0 && pDone == 0){
			pDone ++;			
			r = (r + image[4 * width * (y) + 4 * (x+1) + 0] + image[4 * width * (y+1) + 4 * (x) + 0] + image[4 * width * (y+1) + 4 * (x+1) + 0])/4;
			g = (g + image[4 * width * (y) + 4 * (x+1) + 1] + image[4 * width * (y+1) + 4 * (x) + 1] + image[4 * width * (y+1) + 4 * (x+1) + 1])/4;
			b = (b + image[4 * width * (y) + 4 * (x+1) + 2] + image[4 * width * (y+1) + 4 * (x) + 2] + image[4 * width * (y+1) + 4 * (x+1) + 2])/4;
			}
//if top row of image
			if (y == 0 && pDone==0){
			pDone++;
			r = (r + image[4 * width * (y) + 4 * (x-1) + 0] + image[4 * width * (y) + 4 * (x+1) + 0] + image[4 * width * (y+1) + 4 * (x-1) + 0] + image[4 * width * (y+1) + 4 * (x) + 0] + image[4 * width * (y+1) + 4 * (x+1) + 0])/6;
			g = (g + image[4 * width * (y) + 4 * (x-1) + 1] + image[4 * width * (y) + 4 * (x+1) + 1] + image[4 * width * (y+1) + 4 * (x-1) + 1] + image[4 * width * (y+1) + 4 * (x) + 1] + image[4 * width * (y+1) + 4 * (x+1) + 1])/6;
			b = (b + image[4 * width * (y) + 4 * (x-1) + 2] + image[4 * width * (y) + 4 * (x+1) + 2] + image[4 * width * (y+1) + 4 * (x-1) + 2] + image[4 * width * (y+1) + 4 * (x) + 2] + image[4 * width * (y+1) + 4 * (x+1) + 2])/6;

			}
//if top right corner of image
			if (y == 0 && x == maxWidth && pDone == 0){
			pDone ++;
			r = (r + image[4 * width * (y) + 4 * (x-1) + 0] + image[4 * width * (y+1) + 4 * (x) + 0] + image[4 * width * (y+1) + 4 * (x-1) + 0])/4;
			g = (g + image[4 * width * (y) + 4 * (x-1) + 1] + image[4 * width * (y+1) + 4 * (x) + 1] + image[4 * width * (y+1) + 4 * (x-1) + 1])/4;
			b = (b + image[4 * width * (y) + 4 * (x-1) + 2] + image[4 * width * (y+1) + 4 * (x) + 2] + image[4 * width * (y+1) + 4 * (x-1) + 2])/4;
			}
//if left edge of image			
			if (x == 0 && pDone==0){
			pDone++;
			r = (r + image[4 * width * (y-1) + 4 * (x) + 0] + image[4 * width * (y-1) + 4 * (x+1) + 0] + image[4 * width * (y) + 4 * (x+1) + 0] + image[4 * width * (y+1) + 4 * (x) + 0] + image[4 * width * (y+1) + 4 * (x+1) + 0])/6;
			g = (g + image[4 * width * (y-1) + 4 * (x) + 1] + image[4 * width * (y-1) + 4 * (x+1) + 1] + image[4 * width * (y) + 4 * (x+1) + 1] + image[4 * width * (y+1) + 4 * (x) + 1] + image[4 * width * (y+1) + 4 * (x+1) + 1])/6;
			b = (b + image[4 * width * (y-1) + 4 * (x) + 2] + image[4 * width * (y-1) + 4 * (x+1) + 2] + image[4 * width * (y) + 4 * (x+1) + 2] + image[4 * width * (y+1) + 4 * (x) + 2] + image[4 * width * (y+1) + 4 * (x+1) + 2])/6;
			}
//if right edge of image
			if (x == maxWidth && pDone==0){
			pDone++;
			r = (r + image[4 * width * (y-1) + 4 * (x) + 0] + image[4 * width * (y-1) + 4 * (x-1) + 0] + image[4 * width * (y) + 4 * (x-1) + 0] + image[4 * width * (y+1) + 4 * (x) + 0] + image[4 * width * (y+1) + 4 * (x-1) + 0])/6;
			g = (g + image[4 * width * (y-1) + 4 * (x) + 1] + image[4 * width * (y-1) + 4 * (x-1) + 1] + image[4 * width * (y) + 4 * (x-1) + 1] + image[4 * width * (y+1) + 4 * (x) + 1] + image[4 * width * (y+1) + 4 * (x-1) + 1])/6;
			b = (b + image[4 * width * (y-1) + 4 * (x) + 2] + image[4 * width * (y-1) + 4 * (x-1) + 2] + image[4 * width * (y) + 4 * (x-1) + 2] + image[4 * width * (y+1) + 4 * (x) + 2] + image[4 * width * (y+1) + 4 * (x-1) + 2])/6;
			}
//if bottom left of image
			if (y == maxHeight && x == 0 && pDone == 0){
			pDone ++;			
			r = (r + image[4 * width * (y) + 4 * (x+1) + 0] + image[4 * width * (y-1) + 4 * (x) + 0] + image[4 * width * (y-1) + 4 * (x+1) + 0])/4;
			g = (g + image[4 * width * (y) + 4 * (x+1) + 1] + image[4 * width * (y-1) + 4 * (x) + 1] + image[4 * width * (y-1) + 4 * (x+1) + 1])/4;
			b = (b + image[4 * width * (y) + 4 * (x+1) + 2] + image[4 * width * (y-1) + 4 * (x) + 2] + image[4 * width * (y-1) + 4 * (x+1) + 2])/4;
			}
//if bottom row of image
			if (y == maxHeight && pDone==0){
			pDone++;
			r = (r + image[4 * width * (y) + 4 * (x-1) + 0] + image[4 * width * (y) + 4 * (x+1) + 0] + image[4 * width * (y-1) + 4 * (x-1) + 0] + image[4 * width * (y-1) + 4 * (x) + 0] + image[4 * width * (y-1) + 4 * (x+1) + 0])/6;
			g = (g + image[4 * width * (y) + 4 * (x-1) + 1] + image[4 * width * (y) + 4 * (x+1) + 1] + image[4 * width * (y-1) + 4 * (x-1) + 1] + image[4 * width * (y-1) + 4 * (x) + 1] + image[4 * width * (y-1) + 4 * (x+1) + 1])/6;
			b = (b + image[4 * width * (y) + 4 * (x-1) + 2] + image[4 * width * (y) + 4 * (x+1) + 2] + image[4 * width * (y-1) + 4 * (x-1) + 2] + image[4 * width * (y-1) + 4 * (x) + 2] + image[4 * width * (y-1) + 4 * (x+1) + 2])/6;

			}
//if bottom right of image
			if (y == maxHeight && x == maxWidth && pDone == 0){
			pDone ++;
			r = (r + image[4 * width * (y) + 4 * (x-1) + 0] + image[4 * width * (y-1) + 4 * (x) + 0] + image[4 * width * (y-1) + 4 * (x-1) + 0])/4;
			g = (g + image[4 * width * (y) + 4 * (x-1) + 1] + image[4 * width * (y-1) + 4 * (x) + 1] + image[4 * width * (y-1) + 4 * (x-1) + 1])/4;
			b = (b + image[4 * width * (y) + 4 * (x-1) + 2] + image[4 * width * (y-1) + 4 * (x) + 2] + image[4 * width * (y-1) + 4 * (x-1) + 2])/4;
			}
//if on pixel not on any edges
			if (pDone == 0){
			
			r = (r + image[4 * width * (y-1) + 4 * (x-1) + 0] + image[4 * width * (y-1) + 4 * (x) + 0] + image[4 * width * (y-1) + 4 * (x+1) + 0] + image[4 * width * (y) + 4 * (x-1) + 0] + image[4 * width * (y) + 4 * (x+1) + 0] + image[4 * width * (y+1) + 4 * (x-1) + 0] + image[4 * width * (y+1) + 4 * (x) + 0] + image[4 * width * (y+1) + 4 * (x+1) + 0])/9;
			
			g = (g + image[4 * width * (y-1) + 4 * (x-1) + 1] + image[4 * width * (y-1) + 4 * (x) + 1] + image[4 * width * (y-1) + 4 * (x+1) + 1] + image[4 * width * (y) + 4 * (x-1) + 1] + image[4 * width * (y) + 4 * (x+1) + 1] + image[4 * width * (y+1) + 4 * (x-1) + 1] + image[4 * width * (y+1) + 4 * (x) + 1] + image[4 * width * (y+1) + 4 * (x+1) + 1])/9;
			
			b = (b + image[4 * width * (y-1) + 4 * (x-1) + 2] + image[4 * width * (y-1) + 4 * (x) + 2] + image[4 * width * (y-1) + 4 * (x+1) + 2] + image[4 * width * (y) + 4 * (x-1) + 2] + image[4 * width * (y) + 4 * (x+1) + 2] + image[4 * width * (y+1) + 4 * (x-1) + 2] + image[4 * width * (y+1) + 4 * (x) + 2] + image[4 * width * (y+1) + 4 * (x+1) + 2])/9;
			}
			
			//replaces original rgb with blured rgb

			image[4 * width * y + 4 * x + 0] = r;
			image[4 * width * y + 4 * x + 1] = g;
			image[4 * width * y + 4 * x + 2] = b;
		}
	//encodes the new image data
	error = lodepng_encode32_file(outFilename, image, width, height);
	if(error){
		printf("error %u: %s\n", error, lodepng_error_text(error));
		return 0;
	}
free(image);
return 0;
}

