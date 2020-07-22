#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char * words = "hello";
	words[0] = '\0';
	printf("%s\n",words);
	printf("hello world");
	return 0;
}