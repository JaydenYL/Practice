// implemented by fgets
// fgets(char * restrict str, int size, FILE * restrict stream)

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	char buff[128] ;
	bzero(buff, 128);
	FILE * f = fopen(argv[1], "r");
	while(!feof(f))
	{
		fgets(buff, 127, f);
		buff[127] = 0;
		fprintf(stdout, "%s", buff);
		bzero(buff, 128);
	}
	
	return 0;
}