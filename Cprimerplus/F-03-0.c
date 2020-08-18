#include <stdio.h>

int invert_end(int num, int bits);

int main(int argc, char *argv[]) 
{
	int m = 4, num = 0;
	puts("Enter a number :");
	scanf("%d", &num);
	while(getchar()!= 10);
	printf("num ^ mask = %d\n", invert_end(num, m) );
	
	return 0;
}



int invert_end(int num, int bits)
{
	int mask = 0, bitval = 1;
	while ( bits-- > 0)
	{
		mask |= bitval;
		bitval <<= 1; 
	}
	
	return num ^ mask;
}