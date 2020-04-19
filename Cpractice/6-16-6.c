#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++)
	{
		printf("x = %-4d    x^2 = %-4d    x^3=%-4d\n", i , i*i, i*i*i);
	}
	return 0;
}