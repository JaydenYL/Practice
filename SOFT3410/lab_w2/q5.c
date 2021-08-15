#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	if (argc != 5) {
		fprintf(stderr, "Invalid number of arguments\n");
		exit(1);
	}
	
	int coordinates[4] = {0};
	for (int i = 0; i < 4; i++) {
		coordinates[i] = atoi(argv[i+1]);
		if ( coordinates[i] < 0 || coordinates[i] > 6-i%2 ) {
			fprintf(stdout, "Invalid coordinates\n");
			exit(1);
		}
	}
	
	char map[6][7] = {0};
	map[coordinates[1]][coordinates[0]] = 'S';
	map[coordinates[3]][coordinates[2]] = 'D';
	
	for (int i = 0; i < 6; i++) {
		putchar('|');
		for (int j = 0; j < 7; j++) {
			putchar(map[i][j] ? map[i][j] : ' ');
			putchar('|');
		}
		putchar(10);
	}
	
	
	return 0;
}