#include <stdio.h>

#include "show_bytes.h"
int main(int argc, char *argv[]) 
{
	short a = -12345;
	show_byte((unsigned char *) & a, sizeof(short));
	unsigned short b = a;
	show_byte((unsigned char *) & b , sizeof(short));
	
	return 0;
}