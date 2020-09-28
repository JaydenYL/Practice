#include <stdio.h>

int main(int argc, char *argv[]) 
{
	printf("%lu\n%lu\n%lu\n", sizeof(short)*8, sizeof(int)*8, sizeof(long )*8);
	printf("sizeof(char *) : %lu\n", sizeof(char *));
	
	return 0;
}