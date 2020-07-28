#include <stdio.h>
#include <stdlib.h> // malloc() , free()

int main(int argc, char *argv[]) 
{
	double * db;
	int max ;
	printf("Enter the maximum length of double array: ");
	scanf("%f", &max);
	pd = (double *)malloc(sizeof(double) * max);
	if (pd == NULL )
	{
		puts("Fail in allocating memory");
		exit(EXIT_FAILURE);
	}
}