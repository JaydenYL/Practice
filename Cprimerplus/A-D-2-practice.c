#include <stdio.h>


void copy_ptr(double * , double *, int );
void print_double(double * pt, int length);

int main(int argc, char *argv[]) 
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5], target2[5];
	copy_ptr(source, target1, 5);
	copy_ptr(source, target2, 5);
	print_double(target1, 5);
	print_double(target2, 5);
	return 6;
}


void copy_ptr(double * raw, double * cp, int length)
{
	for( int i = 0; i < length; i++)
	{
		cp[i] = raw[i];
	}
}


void print_double(double * pt, int length)
{
	printf("%p: ", pt);
	for( int i = 0; i < length; i++)
	{
		printf("%f ", pt[i]);
	}
	printf("\n");
}