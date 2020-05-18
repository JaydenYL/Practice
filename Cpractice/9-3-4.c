#include <stdio.h>
#include <stdlib.h> 


void binary(int n);
int scan(void);


int main(int argc, char *argv[]) 
{
//	int number = scan();
	binary(scan());
	return 0;
	
}


void binary(int n)
{
	int r = n % 2;
	if(n >= 2) binary(n / 2);
	putchar('0'+r);
}


int scan()
{
	int num;
	while (scanf("%d", &num) != 1)
	{
		printf("invalid input, please enter an integer: \n");
	}
	return num;
}