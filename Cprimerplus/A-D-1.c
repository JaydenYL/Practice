#include <stdio.h>

void traverse(int  ptr[][2]);

int main(int argc, char *argv[]) 
{
	int array[3][2] = { {1,2}, {3, 4}, {5, 6} };
	traverse(array);
	return 0;
}



void traverse(int ptr[][2])
{
	for (int i = 0 ; i < 6 ; i++)
	{
		printf("%d ", *(ptr+i));
	}
}