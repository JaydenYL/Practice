#include <stdio.h>
#define ROWS 3
#define COLS 4


void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int );
int sum2d(int (*ar)[COLS], int rows);


int main(int argc, char *argv[]) 
{
	int array[ROWS][COLS] = {
		{2, 4, 6, 8},
		{3, 5, 7, 9},
		{12, 10, 8, 6}
	};
	
	sum_rows (array, ROWS);
	sum_cols(array, ROWS);
	printf("sum of all elements is  %d\n", sum2d(array, ROWS) );
	return 0;
	
}


void sum_cols(int ar[][COLS], int rows)
{
	int r, c, total = 0;
	
	for (c = 0; r < rows; r++)
	{
		total += ar[r][c];
	}
	printf("col %d sum : %d\n", c, total);
}


void sum_cols(int ar[][COLS], int rows)
{
	int r, c, total;
	
	for (c = 0; r < rwos; r++)
	{
		total += ar[r][c];
	}
	printf("col %d sum : %d\n", c, total);
}