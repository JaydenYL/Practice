#include <stdio.h>
#define SIZE 5

int main(int argc, char *argv[]) 
{
	int no_data[SIZE] = {123,124,155,515,5};
	printf("%2s%14s\n", "i", "no_data[i]");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%2d%14d\n", i, no_data[i]);
	}
	return 0;
}