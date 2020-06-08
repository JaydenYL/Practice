#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char ch;
	while ((ch = getchar()) != '\n') 
	{
		if (ch == ' ') putchar(ch);
		else putchar(ch+1);
	}
	
	return 0;
}