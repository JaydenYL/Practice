#include <stdio.h>

int main(int argc, char *argv[]) 
{
	short n = -12345;
	unsigned short m = (unsigned short) n;
	printf("n = %d, m = %u\n", n, m);
	
	return 0;
}