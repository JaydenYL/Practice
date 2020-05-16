#include <stdio.h>


char getFirst(void);
char getChoice(void);
void count(void);


int main(int argc, char *argv[]) 
{
	int choice;
	while ((choice = getChoice()) != 'q')
	{
		switch (choice) 
		{
			case 'a' : 
				printf("Buy low , sell high.\n");
				break;
			case 'b' :
				putchar(choice);
				break;
			case 'c' :
				count();
				break;
			default:
				printf("Program Error!\n");
				break;	
		}
	}
	return 0;
}


char getChoice()
{
	int ch;
	
	printf("Enter your choice: \n");
	printf("a. advice  b. bell  \nc. count  q. quit\n");
	
	ch = getFirst();
	
	while ((ch < 'a' || ch > 'c') && ch != 'q')
	{
		printf("Please reponse with a, b, c, q\n");
		ch = getFirst();
	}
	
	return ch;
}


char getFirst()
{
	char ch = getchar();
	while ((getchar()) != '\n') continue;
	return ch;
}


void count()
{
	int n;
	printf("Count how far? Enter the integer: \n");
	scanf("%d", &n);
	for ( int i = 0; i < n; i++) 
	{
		printf("%d", i);
	}
	printf("\n");
}