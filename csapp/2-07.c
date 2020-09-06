#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned , unsigned);

int main(int argc, char *argv[]) 
{
	
	int a = 1 << 31;
	int b = 1 << 31;
	printf(uadd_ok(a, b) ? "OK\n" : "Not ok\n");
	
	a = UINT_MAX;
	b = 1;
	printf(uadd_ok(a, b) ? "OK\n" : "Not ok\n");
	
	a = (b = INT_MAX);
	printf(uadd_ok(a, b) ? "OK\n" : "Not ok\n");
	
	return 0;
	
}


int uadd_ok(unsigned x, unsigned y)
{
	return (0u-x) > y; 
}