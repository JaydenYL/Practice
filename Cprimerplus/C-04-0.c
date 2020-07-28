#include <stdio.h>

extern int rand1();
extern void xrand1(unsigned int );

int main(int argc, char * argv[])
{
	int count;
	unsigned int seed;
	puts("Please enter your choice for seed.\n");
	while (scanf("%u", &seed))
	{
		srand1(seed);
		for (count = 0; count < 5; count ++)
			printf("%d\n", rand1());
		printf("Please enter your next choice: ");
	}
	
	return 0;
}