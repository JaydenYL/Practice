#include <stdio.h>

int mestrlen(const char *);

int main(int argc, char *argv[]) 
{
	char str1[] = "hello world\n";
	printf("%d\n", mestrlen(str1) );
	return 0;
}

int mestrlen(const char * string)
{
	int i = 0;
	for( ; string[i]; i++);
	return i;
}