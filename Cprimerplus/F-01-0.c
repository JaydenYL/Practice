#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int num = 0;
	for(; num < 10; num++)
		printf("~%d = %d\n", num, ~num);
	
	printf("%d & ~%d = %d\n", num, num , num & ~num);
	return 0; 
}