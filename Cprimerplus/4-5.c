#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	int a = printf("%d\n", INT_MAX);
	printf("%d\n",a);
	char b[100];
	b[0] = 65;
	b[1] = 66;
//	scanf("%c", &b);
	printf("%d %d\n", *b, *(b+1));
	printf("%u %u", b , &b[1]);
}