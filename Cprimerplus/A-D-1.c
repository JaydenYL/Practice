#include <stdio.h>

void traverse(int  ptr[][2]);
void traverse_2(int ** ptr, int col , int row);

int main(int argc, char *argv[]) 
{
	int array[3][2] = { {1,2}, {3, 4}, {5, 6} };
	printf("%p %p\n", array, (int **)array);
	traverse(array);
	traverse_2((int **)array, 2, 3);
	return 0;
}



void traverse(int ptr[][2])
{
	printf("traverse:\n");
	size_t SIZE = sizeof(7);
	for (int i = 0 ; i < 6 ; i++)
	{
		printf("%d ", *(int*)((unsigned long)ptr+i*SIZE));
	}
	printf("\n");
}



void traverse_2(int ** ptr, int col , int row)
{
	printf("traverse_2:\n");
	size_t SIZE =  sizeof(int); 
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", *((int*)((unsigned long)ptr + SIZE*col*i + j*SIZE)));
		}
	}
	printf("\n");
}