#include <stdio.h>
#include <stdlib.h>

int contains(char *, char);

int main(int argc, char *argv[]) 
{
	char  buf[256];
	int count;
	if (argc < 3)
	{
		puts("Insufficient arguement\n");
		exit(1);
	}
	FILE * fp = fopen(argv[2], "r");
	if (fp == NULL)
	{
		printf("Error in opening the file %s", argv[2]);
		exit(EXIT_FAILURE);
	}
	while(fgets(buf, 256, fp) != NULL && buf[0] )
	{
		
		if (contains(buf, *argv[1]))
		{
			puts(buf);
			count++;
		}
	}
	
	
	return 0;
	
	
}

int contains(char * str, char ch)
{
	for(int i = 0; str[i]; i++)
		if (str[i] == ch)
			return 1;
			
	return 0;
}
