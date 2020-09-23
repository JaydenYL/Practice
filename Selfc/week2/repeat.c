#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char words[256];
	while(fgets(words, 255, stdin)) // fgets will read the '\n' in the end
	{
		printf("%s", words);
	}
	return 0;
}