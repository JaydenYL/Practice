#include <stdio.h>
#include <stdlib.h>

int stoi(const char *);

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

int stoi(const char * const str)
{
	if (! str) return 0;
	int result = 0;
	for(const char * pt = str; *pt; pt++)
	{
		if (*str != '0' && *str != '1')
		{
			fprintf(stderr, "%s is not a binary number!\n", str);
			exit(-1);
		}
		result <<= 1;
		result += *pt - '0';
	}
	return result;
}