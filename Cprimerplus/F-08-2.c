#include <stdio.h>
#include <stdlib.h>

int stoi(const char * const str);
char * itobs(int, char *);

int main(int argc, char *argv[]) 
{
	if (argc < 3)
	{
		fprintf(stderr, "Insufficient arguments, need 3 but %d\n", argc);
		exit(-1);
	}
	char buf[33];
	int a = stoi(argv[1]), b = stoi(argv[2]);
	fprintf(stdout, "A = %s B = %s\nA ^ B = %s\n", argv[1], argv[2], itobs(a ^ b, buf));
	fprintf(stdout, "A | B = %s\n", itobs(a | b, buf));
	fprintf(stdout, "A & B = %s\n", itobs(a & b, buf));
	
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