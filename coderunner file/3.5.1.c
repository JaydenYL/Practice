#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char ch;
	printf("Please enter a character:");
	scanf("%c", &ch);
	printf("THe code of %c is %d.\n", ch, ch);
	return 0;	
}