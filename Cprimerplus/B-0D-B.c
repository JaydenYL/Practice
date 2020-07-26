#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
	int data[5] =  {0};
	char str[256];
	while(gets(str)){
		for(int i = 0; str[i]; i++)
		{

			if (isupper((str[i]))) data[1]++;
			else if (islower(str[i])) data[2]++;
			else if (isnumber(str[i])) data[3]++;
			else if (ispunct(str[i])) data[4]++;
		}
		data[0] ++;
	}
	
	printf("words: %d\nupper: %d\nlower: %d\nnum: %d\npunc: %d\n", data[0], data[1], data[2], data[3], data[4]);
	
	return 0;
}