#include <stdio.h>

int sum(int * , int );

int main(int argc, char *argv[]) 
{
	int  array[5] = {2, 6, 8, 12, 14};
	printf("sum of the array is %d\n", sum(array, 5));
	printf("size of pointer is %zd\n", sizeof &array);
}

int sum(int * ar, int n)
{
	return (n == 1) ? *ar : *ar + sum(ar+1, n-1);

}