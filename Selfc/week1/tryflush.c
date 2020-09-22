#include <stdio.h>

extern int var;
int var;

int main(int argc, char *argv[]) {
	var  = 10;
	int n = printf("%d: hello world\n", var);
	printf("%d", n);
	return 0;

}