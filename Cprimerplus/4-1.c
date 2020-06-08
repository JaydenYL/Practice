#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char name[100] ;
	printf("What's your first name?\n") ;
	scanf("%s", name) ;
	scanf("%s", &name[strlen(name)]) ;
	int size = sizeof(name), letters = strlen(name) ;
	printf("size: %d\nnumber of letters: %d\n%s", size, letters, name) ;
	return 0 ;
}