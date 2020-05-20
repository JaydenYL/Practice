#include <stdio.h>

int main(int argc, char *argv[]) 
{
	
	int * p1;
	int array[2] = {100 ,200};
	p1 = array;
	printf("%d  %d\n", *++p1, *p1);
	printf("++(*p) = %d\n", ++(*p1));
	printf("(*p)++ = %d\n", (*p1)++);
	printf("%d   %d\n", array[0], array[1]);
	return 0;
	
}