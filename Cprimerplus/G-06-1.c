#include <stdio.h>

#define PTR(X) printf("%d " #X " is %s\n", __LINE__, X);

int main(int argc, char *argv[]) 
{
//	PTR(__LINE__);
//	PTR(__STDC__);
	PTR(__FILE__);
	PTR(__TIME__);
	
	return 0;
}