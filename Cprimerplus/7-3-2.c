#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char str[100] = {};
	int stat[26] = {};
	for (int i = 0; i <26; i++) {
			printf("%i ", stat[i]);
		}
//	for ( int i = 0; i < 26;i++){stat[i]=0;}
	scanf("%s", str);
	printf("%lu\n", strlen(str));
	for (int i = 0; str[i] != 0; i++) {
		stat[str[i]-'A']++;
	}
	for (int i = 0; i <26; i++) {
		printf("%c = %i\n", i+65,stat[i]);
	}
	return 0;
}