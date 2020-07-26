#include <stdio.h>
#include <string.h>
#include <ctype.h>


void delete_blank(char *);

int main(int argc, char *argv[]) 
{
	char str[100];
	while (gets(str) && str[0])
	{
		delete_blank(str);
		puts(str);
	}
	return 0;
}

void delete_blank(char * str)
{
	size_t len = strlen(str);
	int check_list[len] ;
	for (int i = 0; i < len; i++)
	{
		check_list[i] = (isblank(str[i])) ? 0 : 1;
	}
	int i = 0, cursor = -1;
	while (++cursor < len)
	{
		if (check_list[cursor]) str[i++] = str[cursor];
//		cursor ++;
	}
	while (i < len) 
		str[i++] = '\0';
}