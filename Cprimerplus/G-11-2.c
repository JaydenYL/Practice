#include "G-11-1.h"

#define Har(X, Y) ((X*Y)/(X+Y))

int main(int argc, char *argv[]) 
{
	double x, y;
	puts("Enter two number: ");
	while(scanf("%lf %lf", &x, &y) == 2)
	{
		printf("The harmonic mean of %6.3f and %6.3f is %6.3f\n", x, y, Har(x, y));
		puts("Enter two number: ");
	}
	
	return 0;
}