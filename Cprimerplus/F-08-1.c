#include <stdio.h>

int stoi(char *);

int main(int argc, char *argv[]) 
{
	char  strs[33];
	printf("Enter a binary number(q to quit): ");
	while( scanf("%s", strs)  )
	{
		if (*strs == 'q') break;
		printf("the result is %d\n", stoi(strs));
		printf("Enter a binary number(q to quit): ");
	} 
	
	return 0;
}

int stoi(char * str)
{
	if (! str) return 0;
	int result = 0;
	for(char * pt = str; *str; str++)
	{
		result <<= 1;
		result += *str - '0';
	}
	return result;
}