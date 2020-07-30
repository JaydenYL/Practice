#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	if (argc != 2){
		printf("Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	FILE * fp;
	char ch;
	long count = 0;
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Unable to open the file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while( (ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("The file %s has %ld characters.\n", argv[1], count);
	
	return 0;
}
