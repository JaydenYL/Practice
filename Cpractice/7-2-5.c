#include <stdio.h>

int main(int agrc , char * argv[])
{
	printf("enter a number: ");
	int num;
	scanf("%d", &num);
	int prime = 1, i = 2;
	for (; i *i < num ; i++)
	{
		if (num % i == 0) 
		{
			prime = 0;
			break;
		}
	}
	printf("%d is %s prime\n", num, (prime ? "\b" : "not"));
	if (! prime)
	{
		printf("the divider is %i", i);
	}
}