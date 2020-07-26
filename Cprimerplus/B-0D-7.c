#include <stdio.h>
#include <string.h>

char * string_in(char * , char *);

int main(int argc, char *argv[]) 
{
	char str1[] = "hello world", str2[] = "orr";
	char * pt = string_in(str1, str2);
	printf("%p : %s\n", pt, pt);
	return 0;
}

char * string_in(char * full, char * segment)
{
	for (int i = 0; i < strlen(full) - strlen(segment)+ 1; i++)
	{
		for ( int j = 0; j < strlen(segment); j++)
		{
			if (full[i+j] != segment[j]) break;
			if (j == strlen(segment) - 1) return full + i;
		}
	}
	return NULL;
}