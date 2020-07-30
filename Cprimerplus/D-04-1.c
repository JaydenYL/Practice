#include <stdio.h>
#define LEN 20

int main(int argc, char *argv[]) 
{
	char line[LEN];
	
	while (fgets(line, LEN, stdin) != NULL && line[0] != 10)
	{
		fputs(line, stdout);
	}
	
	return 0;
	
}