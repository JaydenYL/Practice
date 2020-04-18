#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int i = 0, N = 26, M = 1;
	
	while (i < N) 
	{
		int j = 0;
		while (j < M && i < N)
		{
			printf("%c", i+'A');
			i++;
			j++;
		}
		M++;
		printf("\n");
	}
	
	return 0;
}