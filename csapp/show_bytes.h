#include <stdio.h>

void show_byte(unsigned char *, int);

void show_byte(unsigned char * pt, int len)
{
		for(int i = 0; i < len ; i ++)
	{
		printf("%x%c", pt[i], (i < len -1) ? 32 : 10);
	}
}