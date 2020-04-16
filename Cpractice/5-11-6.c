#include <stdio.h>

int square(int a);

int main(int argc, char *argv[]) 
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", square(i));
	}
	return 0;
}

int square(int a) 
{
	return a*a;
}