#include <stdio.h>

int main(int argc, char *argv[]) {
	int x[100];
	x[0] = 66;
	printf("the address of x[0]: %p %u\n", &x[0], &x);
	int *p = &x[0];
	printf("p = %d, *p = %d\n", p, *p);
	scanf("%x", & p);
	printf("value: %d address: %p\n", *p, p);
	return 0;
}