#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int times;
	if (argc < 2 || (times = atoi(argv[1])) < 1) 
		printf("Invalid arguement");
	else 
		for( int i = 0 ; i < times; i++) puts("hello world");
	
	return 0;
}