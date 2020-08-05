#include <stdio.h>
#define  MAXTITL  64
#define  MAXAUTH  64

struct book{
	char  title[MAXTITL];
	char  auth[MAXAUTH];
	float value;
};


int main(int argc, char *argv[]) 
{
	struct book abook;
	printf("Please enter the book title : ");
	gets(abook.title);
	printf("Now enter the author : ");
	gets(abook.auth);
	printf("Enter the price of the book : $");
	scanf("%f", &abook.value);
	printf("\e[3;33m%s\e[0m by \e[0;31m%s \e[0m: \e[0;30m$%.2f[0m\n", abook.title, abook.auth, abook.value);	
	
	return 0;
	
}