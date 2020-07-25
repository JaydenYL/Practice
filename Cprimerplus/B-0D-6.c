#include <stdio.h>

char * str_copy(char *, char *, int);

int main(int argc, char *argv[]) 
{
	char str1[100];
	char str2[] = "hello world";
	char * pt = str_copy(str1, str2, 12);
	printf("pt:  %s  %p\nstr1: %s %p\n", pt, pt, str1, str1);
	puts(str1);
	return 0;
}

char * str_copy(char * copy, char * origin, int n)
{
	int i = 0;
	char * pt = copy;
	
	while (*origin && (i++ < n))
		*pt++ = *origin++;
	

	
	return copy;
}