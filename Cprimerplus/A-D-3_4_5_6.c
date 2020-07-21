# include <stdio.h>
# include <limits.h>
# include <float.h>

int max_int(int *, int);
int max_double_index(double *, int);
double max_difference(double *, int);

int main(int agrv, char ** argc)
{
	int ls_int[6] = {7 , 8, 10, 18, 0, 6};
	double ls_double[5] = {12.3, 87.8, 100.9, 129.1, -10.12};
	printf("Max int : %d\n", max_int(ls_int, 6));
	printf("The index of max double : %d\n", max_double_index(ls_double, 5));
	printf("The max difference of double array : %.2f\n", max_difference(ls_double, 5));
	return 0;
}


int max_int(int * pt, int length)
{
	int max = INT_MIN;
	for ( int i = 0; i < length; i++ )
	{
		if (max < pt[i]) max = pt[i];
	}
	return max;
}

int max_double_index(double * pt, int length)
{
	double max = DBL_MIN;
	int idx = 0;
	for ( int i = 0; i < length; i++ )
	{
		if (max < pt[i]) 
		{
			max = pt[i];
			idx = i;	
		}
	}
	return idx;
}


double max_difference(double * pt, int length)
{
	double min = DBL_MAX, max = DBL_MIN;
	for (int i = 0; i < length; i++)
	{
		if (max < pt[i]) max = pt[i];
		if (min > pt[i]) min = pt[i];
	}
	return max - min;
}