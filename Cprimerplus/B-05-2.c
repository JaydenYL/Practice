// strcmp --- string compare

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	char try[40], answer[] = "hello";
	puts("password: ");
	while(strcmp(gets(try), answer) ) 
		printf("Not currect: ");
	puts("correct !");
	
	return 0;
	
}