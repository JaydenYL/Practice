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
	char * ptstr[LINE];
	int n = 0;
	printf("Input up to %d lines. (Terminator : \"\")\n", LINE); 
	while ( n < LEN  &&  gets(input[n])  &&  input[n][0] )
	{
		ptstr[n] = input[n];
		n ++;
	}
	sort_string(ptstr, n);
	for ( int i = 0; i < n; i++)
	{
		puts(ptstr[i]);
	}
	
	return 0;
	
}

void sort_string(char * string[], int num)
{
	if (!num || num == 1) return ;
	char * tmp ;
	for ( int i = 0; i < num ; i++)
	{
		for (int j = i, up = num-i-1; j < up; j++)
		{
			if (strcmp(string[j], string[j+1]) > 0)
			{
				tmp = string[j];
				string[j] = string[j+1];
				string[j+1] = tmp;
			}
		}
	}
}