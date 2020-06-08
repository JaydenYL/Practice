#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	char str[100];
	scanf("%s", str);
	int len = strlen(str);
	for ( int i = len - 1; i>=0; i--) {
		printf("%c", str[i]);
	}
}