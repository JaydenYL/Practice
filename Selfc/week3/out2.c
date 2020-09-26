//  implemented by fread
//  size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	int count = 0, errno = 0;
	char buff[128] = {0};
	FILE * f = fopen(argv[1], "r");
	while(!feof(f))
	{
		count = fread (buff, sizeof (char), 128, f);
		fprintf(stdout, "%s", buff);
		int n = feof (f);
		printf ("%d,%d\n", count, n);
		printf ("%s\n",strerror (errno));
	}
	
	return 0;
}