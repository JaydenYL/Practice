#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char ch ;
	scanf("%c", &ch);
	for (int j = ch; j >= 'A'; j--){
		for ( int i = ch; i >= j; i--) 
		{
			printf("%c", i);
		}
		printf("\n");
	}
}
