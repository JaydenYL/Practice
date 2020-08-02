#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int ch;
	long count;
	fprintf(stdout, "Enter the file name: ");
	char  filename[50];
	scanf("%s", filename);
	FILE * fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stdout, "Fail in openeing the file: %s\n", filename);
	}
	while((ch = fgetc(fp)) != EOF)
	{
		fputc(ch, stdout);
		count ++;
	}
	fclose(fp);
	printf("File has %ld characters.\n", count);
	
	return 0;
	
}