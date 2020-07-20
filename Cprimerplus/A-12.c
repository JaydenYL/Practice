#include <stdio.h>

int sum2d(int, int , int[*][*]);

int main(int argc, char *argv[]) 
{
	int array[3][4] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};
	printf("total = %d", sum2d(3, 4, array));
	return 0;
}



int sum2d(int rows, int cols, int ar[rows][cols])
{
	int total = 0;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			total += ar[r][c];
		}
	}
	return total;
}