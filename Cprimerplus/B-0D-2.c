#include <stdio.h>

void get_input(int, char *);

int main(int argc, char *argv[]) 
{
	int n = 5;
	char str[100] = {[99] = '\0'};
	printf("enter the number of character: ");
	scanf("%d", &n);
	getchar();
	get_input(n, str);
	puts(str);
	return 0;
}

void get_input(int n, char * str)
{
	for (int i = 0, ch; i < n ; i++)
	{
		ch = getchar();
		str[i] = ch;
		if (ch == ' ' || ch == '\t' || ch == '\n') return;
	}
}