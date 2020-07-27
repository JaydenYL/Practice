#include <stdio.h>

void try_stat(void);

int main(int argc, char *argv[]) 
{
	for (int i = 0; i < 10; i++)
		try_stat();
	return 0;
}

void try_stat(void)
{
	static char i = 97;
	putchar(i++);
}