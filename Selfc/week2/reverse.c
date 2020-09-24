#include <stdio.h>

void reverse();

int main()
{
	reverse();
}

void reverse()
{
	char ch = getchar();
	if (ch != 10){
		reverse();
	}
	if (ch != 10)
		putchar(ch);
}