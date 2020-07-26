#include <stdio.h>

int main(int argc, char *argv[]) {
	char str[10][100];
	int i = -1;
	while (++i < 10 && gets(str[i])){}
	
}