#include <stdio.h>

int main(int argc, char *argv[]) 
{
	float a =320000.0;
	double b = 2.14e9;
	printf("%f can be written %e\n", a, a);
	printf("%f can be written %e\n", b, b);//     用“ %e ”表示科学技术法
	return 0;	
}