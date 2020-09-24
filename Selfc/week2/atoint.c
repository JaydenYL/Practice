#include <stdio.h>
#include <string.h>

int atoi(char *);


int main(int argc, char *argv[]) 
{
	printf("%d\n", atoi("-8675"));
	return 0;
}

int atoi(char * str)
{
	int idx = (str[0] == '-')? -1 : 1;
	int len = strlen(str);
	int end = (str[0] == '-')? 1 : 0;
	int res = 0;
	for(int i = len-1; i >= end; i--)
	{
			res += idx*(str[i] - '0');
			idx *= 10;
	}
	return res;
}

