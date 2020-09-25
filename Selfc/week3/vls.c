#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	FILE * fp = stdin;
	int len = 8;
	size_t i = 0;
	char * str = (char *)realloc(NULL, sizeof(char)*len);
	char ch;
	while((ch = fgetc(fp))!=EOF && ch != '\n'){
		str[i++] = ch;
		if(i == len){
			str = (char *)realloc(str, sizeof(char)*(len+=8));
		}
	}
	
	str[i++] = 0;
	printf("%s\n", str);
	
	return 0;
}