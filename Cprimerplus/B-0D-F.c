#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
	if (argc < 3)
	{
		puts("insufficient argument");
		return -1;
	}
	FILE * fp = fopen("textinput.txt", "r");
	char str[100];
	if(! fp)
	{
		puts("Error opening file");
		return 1;
	}
	while (fgets(str, 100, fp))
	{
		for (int i = 0; str[i];i++){
			putchar(toupper(str[i]));
		}
	}
	fclose(fp);
	return 0;
}