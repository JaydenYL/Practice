#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rand1();

int main(int argc, char *argv[]) 
{
	srand((unsigned int ) time(0));
	int ar[10] = {0};
	for (int i = 0; i < 1000; i++)
	{
		ar[rand1()]++;
	}
	for (int i = 0; i < 10; i++)
		printf("%d: %4d times\n", i, ar[i]);
		
	return 0;
}

int rand1()
{
	return rand()%10;
}