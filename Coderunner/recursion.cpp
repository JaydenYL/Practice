#include<stdio.h>

unsigned long long result;

unsigned long long f(unsigned long long x);

int main()
{	
	scanf  ( "%llu", &result);
	printf("%llu", f(result));
	return 0;	
}

unsigned long long f(unsigned long long x)
{
	unsigned long long result;
	if (x == 1) 
	{
		return 1;
	}
	else
	{
		result = f(x - 1) * x;
		return result;
	}
}

