# include<stdio.h>

int get_int(void);

int main(void){
	int input = get_int();
	printf("%d", input);
}

int get_int(void)
{
	int input;
	char ch;
	while (scanf("%d", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
		{
			putchar(ch);
			printf(" is not an integer.\nPlease enter an integer value\n");
		}
	}
	return input;
}