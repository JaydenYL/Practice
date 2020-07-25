#include <stdio.h>

size_t strlength(char *);
char * question_A(char * );

int main(int argc, char *argv[]) 
{
	char str[] = "h ello world";
	printf("%zu\n", strlength(str));
	printf("%p answer of question A: %p", str, question_A(str));
	return 0;
}

size_t strlength(char * str)
{
	size_t count = 0;
	for ( ; str[count]; count ++);
	return count ; 
}

char * question_A(char * str)
{
	while (str) if (*str++ == ' ') return str ;
	return NULL;
}