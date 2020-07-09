//pointer operations

#include <stdio.h>

void process(int *array[2]);

int main(int argc, char *argv[]) 
{
	int array[5] = {100 ,200, 300, 400, 500};
	int * ptr1, * ptr2, * ptr3;
	int ls[3][2] = { {1,2}, {3, 4}, {5, 6} };
	
	ptr1 = array;
	ptr2 = &array[2];
	process(ls);
	return 0;
}



void process(int *array[2])
{
	int (* pz)[2] = array[1];
	printf("%d %d %d", *pz, pz[1], *(pz+2));
	
}