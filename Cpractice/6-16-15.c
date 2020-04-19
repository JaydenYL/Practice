#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char array[256];
	int len = 0;
	while (len < 256) 
	{
		scanf("%c", &array[len]);
		if (array[len] == '\n') break;
		len ++;
	}
	for (int i = len - 1; i>=0; i--) 
	{
		printf("%c", array[i]);
	}
	return 0;
}