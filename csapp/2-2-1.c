#include <stdio.h>
#include <inttypes.h> // this head file includes macro : PRId32 , PRIu32 and more...



int main(int argc, char *argv[]) 
{
	int32_t a = 1024;
	int32_t b = 0xF ;
	printf("x = %" PRId32 " , y = %" PRId32 "\n", a, b); 
	
	return 0;
}