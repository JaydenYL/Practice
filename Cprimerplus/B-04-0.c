#include <stdio.h>

void put1(const char * string);
int put2(const char *);

int main(int argc, char *argv[]) 
{
	char * str = "hello world!";
	put1(str);
	put2(str);
	return 0;
}


void put1(const char * string)
{
	int i = 0;
	while (string[i] )
		putchar(string[i++]);
	putchar('\n');
}


int put2(const char * string)
{
	int i = 0;
	while (*string)
	{
		putchar(* string++);
		i++;
	}
	return i;
}