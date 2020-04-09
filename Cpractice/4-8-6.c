#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	char first[20] , sur[20];
	scanf("%s%s", first, sur);
	int len_fisrt = strlen(first), len_sur = strlen(sur);
	printf("%s %s\n%*.d %*.d", first, sur, -len_fisrt, len_fisrt, -len_sur, len_sur);
	return 0;
}