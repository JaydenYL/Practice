#include <stdio.h>
#include <stdlib.h> // malloc() , free()



int main(int argc, char *argv[]) 
{
	double * db;
	int number , max ;
	printf("Enter the maximum length of double array: ");
	scanf("%d", &max);
	db = (double *)malloc(sizeof(double) * max);
	if (db == NULL )
	{
		puts("Fail in allocating memory");
		exit(EXIT_FAILURE);
	}
	puts("Enter the values (q to quit):");
	int i = 0;
	while ( i < max && scanf("%lf", &db[i]) == 1)
	{
		++i;
	}
	printf("You have entered %d number.\n", number = i);
	
	for (i = 0; i< number ; i++)
		printf("%f ", db[i]);
	
	free(db);
		
	return 0;
}