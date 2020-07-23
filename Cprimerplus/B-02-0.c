// ctrl + D, stop keyboard input
// ctrl + Z, stop program

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char line[81];
	while(fgets(line, 81, stdin) != NULL)
		puts(line);
	printf("hello");
	return 0;
}