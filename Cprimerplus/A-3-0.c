#include <stdio.h>
#define SIZE 5

int main(int argc, char *argv[]) 
{
	short date[SIZE];
	short * pt_short;
	short index;
	double bills[SIZE];
	double * pt_double;
	pt_short = date;
	pt_double = bills;
	printf("%23s%14s\n", "short", "double");
	for(index = 0; index < SIZE ;index ++)
	{
		printf("pointers + %d: %16p %14p\n", index, pt_short+index, pt_double + index);
	}
	return 0;
}