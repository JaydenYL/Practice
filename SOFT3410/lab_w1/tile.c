#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN (50)

void print_image(char *img);
void draw(char *image,char ch, int ch_w, int ch_h, int pairs[2]);

int main(int argc, char *argv[]) {
	char *image = malloc(LEN*LEN);
	memset(image, ' ', LEN * LEN);
	draw(image, '@', 4, 4, (int[2]){0,0});
	draw(image, '@', 4, 4, (int[2]){15,2});
	print_image(image);
	free(image);
	
	return 0;
}


void draw(char *image, char ch, int ch_w, int ch_h, int coor[2]) {
	for (int i = coor[1]; i < coor[1] + ch_h && i < LEN; i++) {
		for (int j = coor[0]; j < coor[0] + ch_w && j < LEN; j++) {
			*(image + i*LEN +j) = ch;
		}
	}
}


void print_image(char *img) {
	for (int i = 0; i < LEN; i++) {
		putchar('-');
	}
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			putchar(*(img+i*LEN+j));
		}
		putchar(10);
	}
	for (int i = 0; i < LEN; i++) {
		putchar('-');
	}
}