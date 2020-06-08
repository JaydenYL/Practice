#include <stdio.h>

void swap(int *, int *);

int main(int argc, char *argv[]) 
{
	int x = 5, y = 10;
	
	
	printf("Originally x = %d, y = %d.\n", x, y);
	swap(&x, &y);
	printf("After swap, x = %d, y = %d.\n", x, y);
}



void swap(int * a, int * b)
{
	int c = *a;
	*a = *b;
	*b = c;
}