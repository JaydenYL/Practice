//assert 

#include <stdio.h>
#include <math.h>
#define NDEBUG
#include <assert.h>



int main(int argc, char *argv[]) 
{
	double x, y,  z;
	printf("Enter the coordinate : ");
	while( scanf("%lf %lf", &x, &y) == 2)
	{
		z = x*x - y*y;		
		assert(z >= 0);
		printf("sqrt(x^2 - y^2) = %lf\n", sqrt(z));
		fprintf(stdout, "the next coordinate:");
	}
	
	
	return 0;
}