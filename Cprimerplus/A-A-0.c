#include <stdio.h>
#define SIZE 10

int sum(int ar[], int n);
void anothertry(int **);

int main(void)
{
	int marbles[SIZE] = {20, 5, 10, 39, 4, 16,  19, 26, 31, 20};
	long answer;
	answer = sum(marbles, SIZE);
	printf("The total number of marbles is %ld.\n", answer);
	printf("The size of marbles is %lu bytes.\n", sizeof marbles);
	int array[3][4] = {{3, 4, 5, 7}, {7, 8, 0, 9}, {1, 2, 3, 4}};
	anothertry(array);
	return 0;
}

int sum(int *ar, int n)
{
	int  s = 0;
	for (int i = 0; i < n ;i++)
	{
		s += ar[i];
	}
	printf("The size of ar is %zd bytes.\n", sizeof ar);
	return s;
}

void anothertry(int ** ar)
{
//	for (int i = 0; i < 4; i++){}
	printf("size of 2D array is %lu bytes.\n", sizeof ar);
	
}