#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sort(int , int[*]);

int main(int argc, char *argv[]) 
{
	int nums[100];
	srand((unsigned int) time(0));
	for (int i = 0; i < 100; i++)
		nums[i] = rand()%11;
	sort(100, nums);
	for (int i = 0; i < 100; i++)
		printf("%d%c", nums[i], ((i+1) % 10) ?' ':'\n');
		
	return 0;
	
}

void sort(int n, int ar[n])
{
	int tmp;
	for (int i = 0; i < n - 1; i ++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ar[j]< ar[j+1])
			{
				tmp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = tmp;
			}
		}
	}
}

