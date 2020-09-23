#include <stdio.h>

int main(int argc, char *argv[]) {
	char ch;
	while((ch = getchar()) != EOF){
		putc(ch, stdout);
	}
	
	return 0;
}