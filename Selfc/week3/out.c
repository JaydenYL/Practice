#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char ch;
	while((ch = getchar()) != EOF)
	{
		putchar(ch);
	}
	
	if(argc > 2 && argv[1][0] == '-')
	{
		FILE * f;
		for(int i = 2; i < argc; i++)
		{
			f = fopen(argv[i], "r");
			while((ch = fgetc(f)) != EOF )
			{
				fprintf(stdout, "%c", ch);
			}
		}
	}
	
	return 0;
}

