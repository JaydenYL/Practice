#include <stdio.h>

char * pt(char *);

int main(int argc, char *argv[]) 
{
	char * x = pt("hello world\n");
	return 0;
}

char * pt(char * str)
{
	char * pc = str;
	while (*pc) putchar(*pc++);
	
	do {
		putchar(*--pc);
	} while (pc - str);
	
	return pc;
}