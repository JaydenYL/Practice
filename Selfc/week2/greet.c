#include <stdio.h>

int main(int argc, char *argv[]) {
	char name[100];
	printf("What's your name ? ");
	scanf("%s", name);
	if (argc == 2)
	{
		printf("%s ", argv[1]);
	}
	printf("%s\n", name);
	
	return 0;
}