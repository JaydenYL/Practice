#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	if (argc < 3) return 1;
	double base = atof(argv[1]), result = base;
	int power = atoi(argv[2]);
	int i = 0;
	while(i < power) result *= base;
	printf("%f", result);
	return 0;
}