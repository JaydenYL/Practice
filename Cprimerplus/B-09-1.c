#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	char  input[100], * stop;
	while (gets(input) && *input)
	{
		printf("convert %ld, stop at %s(%d)\n", strtol(input, &stop, 10),stop, *stop);
	}
	return 0;
}