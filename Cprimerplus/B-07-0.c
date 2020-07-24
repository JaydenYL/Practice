#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpper(char *);
int countPunc(char *);

int main(int argc, char *argv[]) 
{
	char line[100];
	
	puts("Enter a line: ");
	gets(line);
	toUpper(line);
	puts(line);
	printf("count punctuation %d", countPunc(line));
	
	return 0;
}

void toUpper(char * str)
{
	for (int i = 0; str[i] ; i++) 
	{
		if (islower(str[i])) str[i] -= 32;
	}
}

int countPunc(char * str)
{
	int count = 0;
	for (int i = 0; str[i]; i++)
	{
		if (ispunct(str[i])) count++;
	}
	return count;
}