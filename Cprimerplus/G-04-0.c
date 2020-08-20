#include <stdio.h>
#define PRT(n) printf("x%d = %d\n", n, x##n)
#define AA 0
#ifndef AA 
#endif


int main(int argc, char *argv[]) {
	int x1 = 10, x2 = 30;
	PRT(1);
	PRT(2);
	return 0;
}