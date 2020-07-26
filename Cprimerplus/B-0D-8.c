#include <stdio.h>

void str_reverse(char *);

int main(int argc, char *argv[]) 
{
	char str[100];
	gets(str);
	str_reverse(str);
	puts(str);
	return 0;
}

void str_reverse(char * str)
{
	size_t length = strlen(str);
	for (int i = 0, tmp; i < str/2; i++)
	{
		tmp = str[i];
		str[i] = str[length-i-1];
		str[length-i-1] = tmp;
	}
}