// Variable Length Array (VLA) -- from C99
# include <stdio.h>

int sum2d(int rows, int col, int array[rows][col]);

int main(int argc, char *argv[])
{
	int ls[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
	sum2d(4, 2, ls);
	return 0;
	
}

int sum2d(int rows, int col, int array[rows][col])
{
	for ( int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", array[i][j]);
		}
	}
	return 0;
}