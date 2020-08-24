#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_pick(int *, int, int);
void arrayfill(int *, int);

int main(int argc, char *argv[]) 
{
	int array[100];
	arrayfill(array, 100);
	random_pick(array, 100, 30);
	
	return 0;
}



void random_pick(int * pt, int len, int times)
{
	if (times > len)
	{
		fprintf(stdout, "Too many times !\n");
		return ;
	}
	
	srand((unsigned int) time(0));
	for(int i = 0, tmp, idx ; i < times; i ++ )
	{
		idx = rand() % len;
		tmp = pt[idx];
		pt[idx] = pt[len - 1];
		len--;
		printf("%-12d%c", tmp, ((i+1)%6) ? ' ': '\n');
	}
	
}




void arrayfill(int * pt, int len)
{
	srand((unsigned int) time(0));
	for(int i = 0; i < len; i++)
	{
		pt[i] = rand();
	}
}