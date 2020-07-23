// strcat --- string concatenation
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	char str1[99] ;
	char str2[] = "HELLO WORLD";
	
	puts("enter a sentence");
	gets(str1);
	strcat(str1, str2);
	puts(str1);
	puts(str2);
	
	return 0;
	
}