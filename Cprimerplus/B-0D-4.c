#include <stdio.h>

char * str_search(const char *,  char);

int main(int argc, char *argv[]) 
{
	char str[] = "hello world";
	char * ch = str_search(str, 'p');
	printf("address of str: %p, \naddress of  ch: %p", str, ch);
	return 0;
}

char * str_search(const char * str,  char ch)
{
	while (*str)
	{
		if (*str == ch) return (char*) str;
		str++;
	}
	return NULL;
}