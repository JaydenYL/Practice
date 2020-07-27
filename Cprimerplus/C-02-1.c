#include <stdio.h>

extern int count;
static int total = 0

void accumulate(int);

void accumulate(int k);
{
	static int subtotal = 0;
	if (k < 0)
	{
		printf("loop circle: %d\n", count);
		printf("subtotal: %d, total: %d\n", subtotal, total);
	}
	else 
	{
		substotal += k;
		total += k;
	}
}