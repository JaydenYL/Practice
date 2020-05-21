#include <stdio.h>

int main(int argc, char *argv[]) 
{
	
	double rates[4] = {1.0, 3.0, 8.0, 11.0};
	const double * pt = rates;
	double * const conspt = rates;
	pt = &rates[1];
	*conspt = rates[2];
	rates[2] --;
	printf("%4.1f\n", *pt);
	printf("conspt = %f\n", *conspt);
	printf("rated[2]=%f \n",rates[0]);
	return 0;
	
}