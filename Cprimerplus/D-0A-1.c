#include <stdio.h>

int main(int argc, char *argv[]) 
{
	FILE * fp;
	int k;
	fp = fopen("textinput.txt", "w");
	for (k = 0; k < 3; k++)
		fputs("fpust\n", fp);
	
	fclose(fp);
		
	return 0;
}