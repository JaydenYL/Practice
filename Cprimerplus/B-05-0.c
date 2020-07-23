#include <stdio.h>
#include <string.h>

void fit (char *, unsigned int);

int main(int argc, char *argv[]) 
{
	char mesg[] = "hello world!";
	
	puts(mesg);
	fit(mesg, 8);
	puts(mesg);
	puts(mesg+9);
	
	
	return 0;
	
}

void fit(char * str, unsigned int size)
{
	if (strlen(str) > size)
		*(str + size) = '\0';
	
}