//qsort(void *__base, size_t __nel, size_t __width, int (* _Nonnull __compar)(const void *, const void *))	
#include <stdio.h>
#include <stdlib.h>

#define SIZE 40;

void fillarray(double ar[], int n);
void showarray(double ar[], int n);
int mycomp(const void * p1, const void * p2);

int main(int argc, char *argv[]) 
{	
	double array[SIZE];
	fillarray(array, SIZE);
	puts("Random list:");
	showarray(array, SIZE);
	qsort(array, SIZE, sizeof(double), mycomp);
	puts("Sorted list:")
	showarray(array, SIZE);
	
	return 0;
}



void fillarray(double ar[], int n)
{
	for (int i = 0; i < n; i++)
		ar[i] = (double) rand()/(rand() + 0.1);
		
}



void showarray(double ar[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%lf%c", ar[i], ((i+1)%10)? ' ': '\n');
}



int mycomp(const void * p1, const void * p2)
{
	const double * db1 = (const double *) p1;
	const double * db2 = (const double *) p2;
	
	return (int)(* db1 - * db2); 
	
}