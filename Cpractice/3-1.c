#include <stdio.h>


int main(int argc, char *argv[]) {
	#include <inttypes.h>
	int_fast32_t x = 65535;
	printf("%d, %d\n", x, x);
	unsigned short int y = 0;
	printf("y : %lu,  x : %lu\n", sizeof(y), sizeof(x));
	float z = 40;
	printf("%A", z);
	return 0;
}