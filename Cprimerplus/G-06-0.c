#include <stdio.h>

int main(int argc, char *argv[]) 
{

		printf("\b\r%s %s\n", __DATE__, __TIME__);
		sleep(3);
		printf("\b\r%s %s", __DATE__, __TIME__);

	
	return 0;
}