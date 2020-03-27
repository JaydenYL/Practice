#include <stdio.h>

int main(int argc, char *argv[]) {
	for (int i = 3; i > 0 ; i--) {
		for (int j = i; j > 0; j--) {
			printf("Smile!%c", (j == 1)? '\n': '\0');
		}
	}
	return 0;
}