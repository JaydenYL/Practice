//different value after each run

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int32_t a = 0xFEDCBA98 << 32;
	int32_t b = 0xFEDCBA98 >> 36;
	unsigned c = 0xFEDCBA98u >> 40 ;
	printf("%0#x\n", a);
	printf("%0#x\n", b);
	printf("%0#x\n", c);
	
	return 0;
}