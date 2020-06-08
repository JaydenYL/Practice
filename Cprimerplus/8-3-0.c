#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int ch;
	FILE * fb;
	char name[50];
	printf("Enter the name of file: ");
	scanf("%s", name);
	fb = fopen(name, "r");
	if (fb == NULL) 
	{
		printf("Failed to open the file, Bye\n");
		exit(1);
	}
	while ((ch = getc(fb)) != EOF)
	{
		putchar(ch);
	}
	fclose(fb);
	return 0;

}