//

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int a = 0xFEDCBA98 << 32;
	int b = a >> 36;
	unsigned c = a >> 40 ;
	printf("%0#x\n", a);
	printf("%0#x\n", b);
	printf("%0#x\n", c);
	
	return 0;
}