#include <stdio.h>

static int times = 0 ;

void record_circle_times(void);


int main(int argc, char *argv[]) {
	for (int i = 0; i < 10; i++) record_circle_times();
	printf("Times : %d\n", times);
	
	return 0;
}


void record_circle_times(void)
{
	times++;
}