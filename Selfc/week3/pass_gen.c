#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
	size_t len = atoi(argv[1]);
	char passw[len];
	time_t t;
	srand((unsigned int) time(&t));
	
	char ch;
	for(int i = 0; i < len; i++)
	{
		
		while((ch = rand()))
		{
			if (ch > 32 && ch < 127)
				break;
		}
		putchar(ch);
	}
	
	putchar(10);
	
	return 0;
}