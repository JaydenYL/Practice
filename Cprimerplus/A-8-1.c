// time.h, rand(), 
// srand(unsigned seed)  :set seed for rand()

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
	time_t t;
	srand((unsigned) time(&t));
	for (int i = 0 ; i< 10 ; i++)
	{
		printf("%d\n", rand());
	}
	return 0;
}