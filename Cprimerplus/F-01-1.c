#include <stdio.h>

char * itobs(int , char *);
static int size = 8 * sizeof(int);

int main(int argc, char *argv[]) 
{
	char bin_str[size + 1];
	int num;
	
	printf("Enter a number and see it in binary: \n");
	printf("Non-numeric input terminates the program\n");
	while (scanf("%d", &num) == 1) 
	{
		itobs(num, bin_str);
		fputs(bin_str, stdout);
		putchar(10);
	}
	
	return 0;
	
}

char * itobs(int num, char * cp)
{
	for(int i = size-1; i >=0 ; i--)
	{
		cp[i] = (num&01) + '0';
		num >>= 1;
	}
	cp[size] = 0;
	return cp;
}