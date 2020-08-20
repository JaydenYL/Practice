#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE (int)sizeof(int)*8

int stoi(const char * const str);
int rotate(int num, int bit);
char * itobs(int num, char * cp);


int main(int argc, char *argv[]) 
{
	char strs[INT_SIZE + 1], buf[INT_SIZE +1];
	int b, result;
	printf("Enter a binary number(q to quit): ");

	while(scanf("%s", strs))
	{
		if (*strs == 'q')
			exit(1);
		printf("Enter the bits you want to move: ");
		scanf("%d", &b);
		while(getchar()!=10);
		
		result = stoi(strs);
		result = rotate(result, b);
		printf("\e[31mBefore: %s\n\e[32mAfter : %s\n\e[0m", strs, itobs(result, buf));
		
		printf("Enter a binary number(q to quit): ");
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
		result |= *pt - '0';
		
	}
	return result;
}



int rotate(int num, const int bit)
{
	int buf = 0;
	for (int i = 0; i < bit; i ++)
	{
		buf <<= 1;       // buf should be operated before `or` operation 
		buf |= ((unsigned)num >> (SIZE - 1));
//		printf("buf: %s\n", itobs(buf, buff));
		num <<= 1;
	}
	return num | buf;
	
}



char * itobs(int num, char * cp)
{
	for(int i = INT_SIZE-1; i >=0 ; i--)
	{
		cp[i] = (num&01) + '0';
		num >>= 1;
	}
	cp[size] = 0;
	return cp;
}