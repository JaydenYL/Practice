#include <stdio.h>
#define RED  	"\e[3;31m"
#define L_RED	"\e[3;31m"
#define NONE	"\e[0m"


int main(int argc, char *argv[]) 
{
	printf("[%2u]" RED "RED " L_RED "L_RED\n" NONE, __LINE__);
	return 0;
}