#include <stdio.h>
#include <inttypes.h>

void sub_function();

int main(int argc, char *argv[]) 
{
	int16_t a=4573;
	//printf("First, assume int16_t is  short.\n");
	printf("int16_t = %hd \n", a);
	printf("a = %"PRId16"\n", a);//注意 PRId的大小写。。。   d是小写。
	sub_function();
	return 0;	
}

void sub_function() 
{
	int b = 255;
	int8_t a =b;
	//scanf("%d", &a);
	printf("This is int_8 result %d = %"PRId8"\n", b, a); 
}