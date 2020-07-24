// sort string

#include <stdio.h>
#include <string.h>
#define LINE 20
#define LEN 128
#define TER " "

void sort_string(char * string[], int num);

int main(int argc, char *argv[]) 
{
	char input[LINE][LEN];
	char * ptstr;
	int n = 0;
	printf("Input up to %d lines. (Terminator : \"\")\n"); 
	while (n < LEN && gets(input[n]) != NULL && !inputs[n][0] )
	{
		ptstr[n] = input[n];
		n ++;
	}
	sort_string(ptstr, n);
	for ( int i = 0; i < n; i++)
	{
		puts(ptstr);
	}
	
	return 0;
	
}

void sort_string(char * string[], int num)
{
	char * pt;
	for ( int i = 0; i < num ; i++)
	{
		
	}
}