#include <stdio.h>

int main(int argc, char *argv[]) {
	char str[10][100];
	int i = -1;
	while (++i < 10 && gets(str[i])){}
	puts("A. origin\nB. ASCII\nC. length of whole char *\nD. length of the first word\nE. quit");
	while(1)
	{
		switch (getchar()) 
		{
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			default:
				puts("Invalid input, enter your choice agian: ");
		}
		while(getchar()!= '\n') 
			getchar();
	}
}