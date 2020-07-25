#include <stdio.h>

char * input(int n, char str[n]);

int main(int argc, char * argv[])
{
	char str[11] = {[10] = '\0'};
	input(10, str);
	puts(str);
	return 0;
	
}

char * input(int n, char str[n])
{
	for(int i = 0; i < n; i++)
	{
		str[i] = getchar();
	}
	return str;
}