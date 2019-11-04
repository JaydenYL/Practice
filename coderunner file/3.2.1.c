#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[]) 
{	
	int ten =10;
	int two = 2;
	unsigned int a = 4294967295;
	printf("%d minus %d is %d.\n", ten,two,ten-two);
	printf("%f\n", pow(16, 4));
	printf("%d, %#o, %#x\n", ten, ten, ten);//打印十进制，八进制，和十六进制数， 并显示前缀“ # ”
	printf("%u, %u, %u, %#x\n", a, a+1, a+2, a);//unsigned int 打印用" %u "
	printf("\t\v%d", two);
	return 0;
}