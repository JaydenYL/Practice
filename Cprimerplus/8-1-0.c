#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{
	char ch;
	int count = 0;
	while (( ch = getchar())!= EOF ) 
	{
		if (ch == '\n' ) continue;
		putchar(ch+32);
		printf("\n");
		count ++;
	}
	printf("count = %d, ch(EOF) = %d\n", count, ch);
	return 0;
}