#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int x = 30;
	while(x++ < 33)
	{
		int x  = 100;
		printf("x in inner block: %d\n", x);
		x ++;
	}
	
	printf("%d", x);
	
	return 0;
}