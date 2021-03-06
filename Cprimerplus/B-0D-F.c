#include <stdio.h>
#include <string.h>
#include <ctype.h>

int notChange(int);

int main(int argc, char *argv[]) 
{
	if (argc < 3)
	{
		puts("insufficient argument");
		return -1;
	}
	FILE * fp = fopen(argv[1], "r");
	char str[100] ;
	if(! fp)
	{
		puts("Error opening file");
		return 1;
	}
	
	
	int (* fun)(int);
	if (!strcmp(argv[2], "-p")) fun =  notChange;
	else if (!strcmp(argv[2], "-u")) fun = toupper;
	else if (!strcmp(argv[2], "-l")) fun = tolower;
	else {
		printf("Invalid choice: %s", argv[2]);
		return 2;
	}
	
	while (fgets(str, 100, fp))
	{
		for (int i = 0; str[i];i++) 
			putchar(fun(str[i]));
	}
	puts("");
	fclose(fp);
	
	return 0;
}

int notChange(int i){ return i;}