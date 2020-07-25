#include <stdio.h>

int str_search(const char *,  char);

int main(int argc, char *argv[]) 
{
	char str[] = "hello world";
	int ch = str_search(str, 'h');
	printf("%d", ch);
	return 0;
}

int str_search(const char * str,  char ch)
{
	while (*str)
	{
		if (*str == ch) return 1;
		str++;
	}
	return 0;
}