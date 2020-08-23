#include "G-11-1.h"

#define PI 4*atan(1)

int main(int argc, char *argv[]) 
{
	double angle, len, x , y ;
	printf("Please enter a polar coordinates: ");
	while(scanf("%lf %lf", &angle, &len) == 2)
	{
		x = len * cos(angle*PI/180);
		y = len * sin(angle*PI/180);
		printf("Cartesian coordinates: (%8.4lf, %8.4lf)\n", x, y);
		printf("Please enter a polar coordinates: ");
	}
	
	
	return 0;
}