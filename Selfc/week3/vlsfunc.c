#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * getString(FILE *);

int main(int argc, char *argv[]) {
	char ** str;
	char * tmp = getString(stdin);
	str = & tmp;
	printf("%s\n", *str);
	return 0;
}

char * getString(FILE * fp)
{
	int len = 8;
	size_t i = 0;
	char * str = realloc(NULL, sizeof(char)*len);
	char ch;
	while((ch = fgetc(fp))!=EOF && ch!='\n' && ch != ' '){
		str[i++] = ch;
		if(i == len){
			str = realloc(str, sizeof(char)*(len+=8));
			if (!str) return  str;
		}
	}
	
	str[i++] = 0;
	return (char *)realloc(str, sizeof(char)*i);
	
}