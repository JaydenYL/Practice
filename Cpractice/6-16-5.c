#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char ch;
	scanf("%c", &ch);
	for (int i = 'A'; i <= ch ; i++) 
	{
		int j = 'A';
		for (; j <= i; j++)
		{
			printf("%c", j);
		}
//		printf("%c", j);
		j -= 2;
		for (; j >= 'A'; j--)
		{
			printf("%c", j);
		}
		printf("\n");
	}
}