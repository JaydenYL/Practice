#include <stdio.h>
#include <string.h>
#include <ctype.h>


void delete_blank(char *);

int main(int argc, char *argv[]) 
{
	char str[100];
	while (gets(str))
	{
		
	}
}

void delete_blank(char * str)
{
	size_t len = strlen(str);
	int check_list[len] ;
	for (int i = 0; i < len; i++)
	{
		check_list[i] = (isblank(str[i])) ? 0 : 1;
	}
	
	for (int cursor = 0, i = 0; cursor < len; cursor ++ )
	{
		if (check_list[cursor]) str[i++] = str[cursor];
	}
	
}