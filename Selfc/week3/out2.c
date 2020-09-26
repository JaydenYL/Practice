//  implemented by fread
//  size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	char buff[100];
	while(fread(buff, 100, sizeof(char), stdin) != EOF)
	{
		fprintf(stdout, "%s", buff);
		memset(buff, 0, 100);
	}
	
	return 0;
}