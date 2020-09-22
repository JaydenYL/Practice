#include <stdio.h>


int var;

int main(int argc, char *argv[]) {
	var  = 10;
	int n = printf("%d\n", var);
	printf("%d", n);
	fflush(stdout);
	return 0;

}