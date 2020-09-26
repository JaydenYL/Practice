#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
	const float PI = 3.1415F;
	double r;
	puts("Please enter the radius of the sphere: ");
	scanf("%lf", &r);
	printf("The volume : %lf\n", PI*pow(r, 3)*4/3);
	
	return 0;
}