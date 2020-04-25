#include <stdio.h>

int main(int argc, char *argv[]) 
{
	
	int i = 0, newline = 0;
	char c;
	while ( (c = getchar()) != '#') 
	{
		if (c == '\n') newline ++;
		else i ++ ;
	}
	printf("newline:%d alpha: %d", newline, i);
	
}