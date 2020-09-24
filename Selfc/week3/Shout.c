#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
	char ch;
	while((ch = getchar()) != EOF){
		if (islower(ch))
		{
			putchar(ch-32);
		} 
		else 
		{
			putchar(ch);
		}
	}
	
	return 0;
}