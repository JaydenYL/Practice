#include <stdio.h>
#include <stdlib.h>

int main() {

	char* str = "Please enter passport code:";
	printf("%s\n", str);
	char user ;
	scanf("%c", &user);

	if (user == '0') 
	{

		char* str2 = "Please enter passport digit:";
		printf("%s\n", str2);
		char num ;
		scanf("%c", &num);
		if (num == '\n') scanf("%c", &num);

		if (atoi(&num) > 4) {
			char* final_str = "Sorry, Visa denied.";
			printf("%s\n", final_str);
			return 0;
		}
		else {
			char* final_str = "Hello World!";
			printf("%s\n", final_str);
			return 0;
		}
	}
}