#include <stdio.h>
#define SIZE 5

int main(int argc, char *argv[]) 
{
	int a[SIZE] = {1, 23, 32, 89};
	int b[SIZE];
	
	for (int i = 0; i< SIZE ; i++)
	{
		printf("%d	 %d\n", a[i], b[i]);
	}
	
//	b = a; 					incorrect 	-- 	 error: array type 'int [5]' is not assignable
//	a = {10, 9, 8, 7, 6};	incorrect, not assignable besides initialization

	for (int i = 0; i< SIZE ; i++)
	{
			printf("%d	 %d\n", a[i], b[i]);
	}
	
}