#include <stdio.h>

int uadd_ok(unsigned , unsigned);

int main(int argc, char *argv[]) 
{
	int a = 1 << 31;
	int b = 1 << 31;
	
	printf(uadd_ok(a, b) ? "OK\n" : "Not ok\n");
	
	return 0;
	
}

int uadd_ok(unsigned x, unsigned y)
{
	return (0u-x) > y; 
}