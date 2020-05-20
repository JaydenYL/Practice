#include <stdio.h>

int main(int argc, char *argv[]) 
{
	double rates[4] = {1.0, 3.0, 8.0, 11.0};
	const double * pt = rates;
	pt = &rates[1];
	rates[2] --;
	printf("rated[2]=%f \n",rates[2]);
	return 0;
}