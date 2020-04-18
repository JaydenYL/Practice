#include <stdio.h>

void printCube(double f)
{
	printf("%.4f^3 = %.4f", f, f*f*f);
}

int main(int argc, char *argv[]) 
{
	double num;
	scanf("%lf\n", &num);
	printCube(num);
}
