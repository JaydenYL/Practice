#include <stdio.h>


void function_1(void);
void function_2(void);

int main(int argc, char *argv[]) 
{
	atexit(function_1);
	int num;
	if(scanf("%d", &num) != 1)
	{
		atexit(function_2);
		printf("Not a number\n");
		exit(-1);
	}
	
//	return 0;
}

void function_1(void)
{
	puts("exit with function 111")
}

void function_2(void)
{
	puts("exit with function 222");
	
}