#include <stdio.h>

int atoi(char *);

int main(int argc, char *argv[]) 
{
	printf("%d\n", atoi("-8675"));
	return 0;
}

int atoi(char * str)
{
	int idx = 1;
	int res = 0;
	for(int i = 0; str[i]; i++)
	{
		if (str[i] == '-'){
			idx = -1;
		}else{
			res += idx*(str[i] - '0');
			idx *= 10;
		}
	}
	return res;
}