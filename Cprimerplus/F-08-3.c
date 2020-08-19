#include <stdio.h>

int count_open_bits(int );
char * itobs(int, char *);


int main(int argc, char *argv[]) 
{
	int n;
	char buf[sizeof(int)*8 + 1];
	printf("Enter a number: ");
	while(scanf("%d", &n) ==1)
	{
		printf("number of open bits if %d : %d\n", n, count_open_bits(n));
		printf("%s\n", itobs(n, buf));
		printf("Enter a number(q to quit): ");
	}
	return 0;
}


int count_open_bits(int num)
{
	int size = sizeof(int)*8, count = 0;
	for(; size > 0; size--)
	{
		count += num & 1;
		num >>= 1;
	}
	return count;
}


char * itobs(int num, char * cp)
{
	int size = sizeof(int)*8;
	for(int i = size-1; i >=0 ; i--)
	{
		cp[i] = (num&01) + '0';
		num >>= 1;
	}
	cp[size] = 0;
	return cp;
}