#include <stdio.h>
#include <stdlib.h>
#define SIZE sizeof(int)*8

int stoi(const char * const str);
int rotate(int num, int bit);
char * itobs(int num, char * cp);


int main(int argc, char *argv[]) 
{
	char * strs[SIZE + 1], buf[SIZE +1];
	int b, result;
	printf("Enter a binary number: ");
	while(scanf("%s", strs))
	{
		printf("Enter the bits you want to move: ");
		scanf("%d", &b);
		result = stoi(strs);
		result = rotate(result, b);
		printf("Before: %s\nAfter : %s\n", strs, itobs(result, buf));
		printf("Enter a binary number: ");
	}
	
	
	return 0;
}



int stoi(const char * const str)
{
	if (! str) return 0;
	int result = 0;
	for(const char * pt = str; *pt; pt++)
	{
		if (*str != '0' && *str != '1')
		{
			fprintf(stderr, "%s is not a binary number!\n", str);
			exit(-1);
		}
		result <<= 1;
		result += *pt - '0';
	}
	return result;
}


int rotate(int num, int bit)
{
	int buf = 0;
	for (int i = 0; i < bit; i ++)
	{
		buf += (num >> (SIZE - 1));
		buf <<= 1;
		num <<= 1;
	}
	num <<= bit;
	return num | buf;
	
}

char * itobs(int num, char * cp)
{
	int size = sizeof(int);
	for(int i = size-1; i >=0 ; i--)
	{
		cp[i] = (num&01) + '0';
		num >>= 1;
	}
	cp[size] = 0;
	return cp;
}