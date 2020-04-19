#include <stdio.h>

int main(int argc, char *argv[]) {
	int array[8];
	array[0] = 2;
	int i = 1;
	while (i < 8) 
	{
		array[i] = array[i-1]*2;
		i++;
	}
	i = 0;
	do {
		printf("%d ", array[i]);
		i++;
	} while (i<8);
}