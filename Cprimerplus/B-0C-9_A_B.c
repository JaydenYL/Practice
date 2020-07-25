#include <stdio.h>

size_t strlength(char *);

int main(int argc, char *argv[]) 
{
	printf("%zu", strlength("hello world"));
	return 0;
}

size_t strlength(char * str)
{
	size_t count = 0;
	for ( ; str[count]; count ++);
	return count ; 
}