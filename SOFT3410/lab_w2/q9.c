#include <stdio.h>
#include <assert.h>

typedef struct Path {
	int * path;
	int size;
} Path;

void print_map(char map[6][7]);
void draw(char map[6][7], int *path, int len, char ch);




int main(int argc, char *argv[]) {
	int coordinates[4] = {1, 1, 4, 3};
	int walls[12] = {3, 0, 3, 1, 3, 2, 3, 3, 3, 4, 2, 3};
	char map[6][7] = {0};
	map[coordinates[0]][coordinates[1]] = 'S';
	map[coordinates[2]][coordinates[3]] = 'D';
	draw(map, walls, 12, 'X');
	print_map(map);
	return 0;
}



void print_map(char map[6][7]) {
	
	for (int i = 0; i < 6; i++) {
		putchar('|');
		for (int j = 0; j < 7; j++) {
			putchar(map[i][j] ? map[i][j] : ' ');
			putchar('|');
		}
		putchar(10);
	}
	
}



void draw(char map[6][7], int *path, int len, char ch) {
	assert(!(len & 0x1));
	for (int i = 0; i < len; i+=2) {
		map[path[i]][path[i+1]] = ch;
	}
}