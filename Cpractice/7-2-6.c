#include <stdio.h>

int main(int argc, char *argv[]) {
	int num;
	printf("Enter an integer: ");
	scanf("%d", &num);
	int i = 2;
	for ( ;i*i <= num; i++ ) {
		if (num%i == 0){
			printf("%d ÷ %d = %d\n", num, i, num/i);
		}
	}
	return 0;
}