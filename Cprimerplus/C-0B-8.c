#include <stdio.h>
#include <stdlib.h>

int* make_array(int , int );
void show_array(int , int[*]);

int main(int argc, char *argv[]) 
{
	int size, value, * pa;
	
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	while (size > 0) 
	{
		printf("Enter the initial value of the array: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
			show_array(size, pa);
			free(pa);
		printf("Enter tht number of elements( < 1 to quit): ");
		scanf("%d", &size);
	}
	
	return 0;
}


int * make_array(int n, int value)
{
	int * pt = (int *)malloc((unsigned int)n*sizeof(int));
	for (int i = 0; i < n; i++)
		pt[i] = value;
	return pt;
}

void show_array(int n, int array[n])
{
	for(int i = 0; i < n; i++)
	{
		printf("%4d%c", array[i], ((i+1)%8)? ' ': '\n');
	}
	putchar(10);
	
}