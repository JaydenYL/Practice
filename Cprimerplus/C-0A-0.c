#include <stdio.h>

char color = 'B';

void first(void);
void second(void);

int main(int argc, char *argv[]) 
{
	extern char color;
	printf("the color in main() is %c.\n", color);
	first();
	printf("the color in main() is %c.\n", color);
	second();
	printf("the color in main() is %c.\n", color);
	
	return 0;
}

void first(void)
{
//	char color ;
	color = 'R';
	printf("the color in first() is %c.\n", color);
	
}


void second(void)
{
//	char color;
	color = 'G';
	printf("the color in second() is %c.\n", color);
}