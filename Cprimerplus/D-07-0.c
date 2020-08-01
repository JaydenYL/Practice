#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define SLEN 81

void append(FILE * source, FILE * dest);

int main(int argc, char *argv[])
{
	FILE * fa, * fs;
	char file_app[SLEN], file_src[SLEN];
	int file_count = 0;
	puts("Enter the name of destination file: ");
	gets(file_app);
	if ((fa = fopen(file_app, "a")) == NULL)
	{
		fprintf(stderr, "Error , cannot open the file.");
		exit(2);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) )
	{
		fputs("Fail in creating output buffer", stderr);
		exit(1);
	}
	puts("Enter the name of first source file (empty line to quit)\n");
	while(gets(file_src) && file_src[0] )
	{
		if (strcmp(file_src, file_app) == 0)
		{
			fprintf(stderr, "Cannot append file to itself.\n");
			continue;
		}
		else if (fs = open(file_src, "r") == NULL)
		{
			fprintf(stderr, "Cannot open file %s", file_src)''
		}
		else 
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) )
			{
				fputs("Fail in creating input buffer", stderr);
				exit(1);
			}
			append(fs, fa);
			if (ferror(fs))
				fprintf(stderr, "Error in reading file %s\n", file_src);
			if (ferror(fa))
				fprintf(stderr, "Error in writing file %s\n", file_app);
			fclose(fs);
			file_count++;
			fprintf(stdout, "File %s appended.\n ", file_src);
			puts("Next file (empty line to quit)\n");
		}
	}
	
	fprintf(stdout, "Done, %d file appended.\n", file_count);
	fclose(fa);
	
	return 0;
}



void append(FILE * source, FILE * dest)
{
	size_t bytes;
	static char tmp[BUFSIZE];
	
	while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(bytes, sizeof(char), bytes, dest);
}