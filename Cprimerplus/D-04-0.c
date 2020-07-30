#include <stdio.h>
#include <stdlib.h>
#define  MAX 40

int main(int argc, char *argv[]) 
{
	FILE *fp;
	char words[MAX];
	
	if ((fp = fopen("words.txt", "a+" )) == NULL)
	{
		fprintf(stdout, "Can't open \"words\" file.\n");
		exit(EXIT_FAILURE);
	}
	puts("Enter words to add to the file : press the enter");
	puts("Key at the begining of a line to terminate.");
	while (gets(words) != NULL && words[0] != 0)
		fprintf(fp, "%s", words);
	
	puts("File content: ");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1)
		fprintf(stdout, "%s", words);
		
	if (fclose(fp))
		fprintf(stderr, "Error closing file\n");
		
	return 0;
	
}