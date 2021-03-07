#include <stdio.h>
#include <stdlib.h>

int my_atoi(char *);

int main(int argc, char *argv[]) {
	char ss[] = "98";
	printf("%d\n", my_atoi(ss));
}

int my_atoi(char * p)
{
//	printf("%s\n", p);
//	if (p[1] == 0)
//	{
//		return p[0]-'0';
//	}
	return  (p[1]) ? (p[0]-'0')*10 + my_atoi(p+1) : p[0] - '0' ;
}