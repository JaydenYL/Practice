// compress to 1/3 of origin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40


int main(int argc, char *argv[]) 
{
	FILE * in, * out;
	char ch, name[LEN];
	int count = 0;
	
	if (argc != 2)
	{
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Fail in opening the file.\n");
		exit(EXIT_FAILURE);
	}
	
	if ((out = fopen("textoutput.txt", "w")) == NULL)
	{
		fprintf(stderr, "Fail in creating output file.\n");
		exit(EXIT_FAILURE);
	}
	
	while((ch = getc(in)) != EOF)
	{
		if (count++ % 3 == 0)
			putc(ch, out);
	}
	
	if (!fclose(in) || !fclose(out))
	{
		fprintf(stderr, "Error in closing files.\n");
		exit(EXIT_FAILURE);
	}
	
	
	return 0;
}