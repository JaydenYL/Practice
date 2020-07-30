// compress to 1/3 of origin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40


int main(int argc, char *argv[]) 
{
	FILE * in, * out;
	char ch, name[LEN];
	int count = 0;
	
	if (argc != 2)
	{
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
}