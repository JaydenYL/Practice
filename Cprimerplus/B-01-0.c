// int array[]   ,then   array++  --- >  will rise en error

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char * const str = "hello world";
//	++str;
//	char pt[] = {'h', 'e', 'l', 'l', ' ', 'w', 'o', 'r', 'l', 'd'};
	int array[] = {1, 2};
	array++;
//	++ pt;
	printf("%s", str);
	return 0 ;
}