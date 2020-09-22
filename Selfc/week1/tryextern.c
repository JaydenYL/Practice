#include <stdio.h>
//#include "thefun.h"
//
// void func();
extern int var;
int var;

int main(int argc, char *argv[]) 
{
	var = 10;
	int n = printf("%d\n", var);
	printf("%d", n);
//	fflush(stdout);
//	func();
	return 0;
}