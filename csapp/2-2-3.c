#include <stdio.h>

#include "show_bytes.h"

int main(int argc, char *argv[]) 
{
	printf("%d\n", -1 < 0u);
	int a = -12345;
	show_byte((unsigned char *) &a, sizeof(int));
	return 0;
}