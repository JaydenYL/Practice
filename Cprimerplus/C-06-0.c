#include <stdio.h>
#include <stdlib.h> // malloc() , free()



int main(int argc, char *argv[]) 
{
	double * db;
	int number , max ;
	printf("Enter the maximum length of double array: ");
	scanf("%f", &max);
	pd = (double *)malloc(sizeof(double) * max);
	if (pd == NULL )
	{
		puts("Fail in allocating memory");
		exit(EXIT_FAILURE);
	}
	puts("Enter the values (q to quit):");
	int i = 0;
	while ( i < max && scanf("%d", &db[i]) == 1)
	{
		++i;
	}
	printf("You have entered %d number.\n", number = i);
	
	for (i = 0; i< number ; i++)
		printf("%f ", db[i]);
		
	return 0;
}