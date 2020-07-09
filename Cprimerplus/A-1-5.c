#include <stdio.h>

int main(int argc, char *argv[]) 
{	// size should > 0
//	int size;
//	while (getchar() != '\n')
//	{
//		scanf("%d", &size);
//		if (size > 0) break;
//		printf("size should be positive: ");
//	}
	int array[12][12]; 	// not allowed in C90,  but allowed in C99 and later
	printf("%lu", sizeof(array));
	return 0;
}