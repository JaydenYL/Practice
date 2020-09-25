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
		
		if(!((ch = rand() >> 8) > 32 && ch < 127 )){
			continue;
		}
		passw[i] = ch;
		
	}
	for(int i = 0; i < len; i++)
	{
		putchar(passw[i]);
	}
	putchar(10);
	
	return 0;
}