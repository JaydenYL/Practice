#include <stdio.h>
#include <ctype.h>

long alphaToInt(char *);

int main(int argc, char *argv[]) 
{
	char str[10];
	while (gets(str) && *str)
		printf("%ld\n", alphaToInt(str));
	
	return 0;
}

long alphaToInt(char * str)
{
	long result = 0 , sign = (*str == '-') ? -1 : 1;
	char * pt = (sign == -1) ? str+1: str;
	while (isnumber(*pt))
	{
		result = result*10 + (*pt++ - '0');
	}
	return sign*result;
}