#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char line[81];
	while(fgets(line, 81, stdin) != EOF)
		puts(line);
	return 0;
}