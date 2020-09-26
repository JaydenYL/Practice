//  implemented by fread
//  size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	int  count = 0;
	char buff[128] ;
	bzero(buff, 128);
	FILE * f = fopen(argv[1], "r");
	while(!feof(f))
	{
		count = fread (buff, sizeof (char), 127, f);
		buff[127] = 0;
		fprintf(stdout, "%s", buff);
		bzero(buff, 128);
		printf("\ncount = %d\n", count);
	}
	
	
	return 0;
}