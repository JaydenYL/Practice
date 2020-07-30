// reverse

#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'
#define SLEN 50


int main(int argc, char *argv[]) 
{
	char ch, file[SLEN];
	FILE * fp;
	long count, last;
	
	puts("Enter the name of the file to be processed: ");
	gets(file);
	
	if((fp = fopen(file, "rb")) == NULL)
	{
		printf("fail in opening %s.\n", file);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	for (count = 1L; count <= last; count++)
	{
		fseek(fp, -count, SEEK_END);
		ch = getc(fb);
		/* For DOS, BUT FUNCTION WELL IN UNIX*/
//		if (ch != CNTL_Z && ch != '\r')
//			putchar(ch);
		/*FOR MAC*/	
		if (ch == '\r')
			putchar(10)
		else putchar(ch)
	}
	putchar(10);
	fclose(fp);
	
	return 0;
}