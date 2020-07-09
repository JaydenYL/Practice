#include <stdio.h>
#define SIZE 10

int sum(int *, int *);

int main(int argc, char *argv[]) 
{
	int marbles[SIZE] = {20, 5, 10, 39, 4, 16,  19, 26, 31, 20};
	long answer = sum(marbles, marbles + SIZE);
	printf("The sum of marbles is %ld", answer);
	return 0;
}

int sum(int * start, int * end)
{
	int total = 0;
	while (start < end)
	{
		total += *start;
		printf("%d , ", *start++);
//		start++;
	}
	return total;
}