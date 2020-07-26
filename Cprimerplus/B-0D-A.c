#include <stdio.h>

int main(int argc, char *argv[]) {
	char str[10][100];
	int i = -1;
	while (++i < 10 && gets(str[i])){}
	puts("A. origin\nB. ASCII\nC. length of whole char *\nD. length of the first word\nE. quit");
}