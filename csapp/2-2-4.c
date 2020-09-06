#include <stdio.h>

#include "show_bytes.h"

int main(int argc, char *argv[]) 
{
	short a = -12345;
	show_byte((unsigned char *) & a, sizeof(short));
	unsigned short b = a;
	show_byte((unsigned char *) & b , sizeof(short));
	int c = a;
	show_byte((unsigned char *) & c, sizeof(int));
	unsigned  d = b;
	show_byte((unsigned char *) & d, sizeof(int));
	
	return 0;
}