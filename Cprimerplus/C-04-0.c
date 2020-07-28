#include <stdio.h>

extern int rand1();
extern void srand1(unsigned int );

int main(int argc, char * argv[])
{
	int count;
	unsigned int seed;
	printf("Please enter your choice for seed: ");
	while (scanf("%u", &seed) == 1)
	{
		srand1(seed);
		for (count = 0; count < 5; count ++)
			printf("%d\n", rand1());
		printf("Please enter your next choice: ");
	}
	
	return 0;
}