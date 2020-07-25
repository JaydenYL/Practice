#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	char str[40] = "hello world";
	char str1[40] = "hello from C";
	strcat(str, str1);
	puts(str);
}