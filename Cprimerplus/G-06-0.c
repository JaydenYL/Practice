#include <stdio.h>

int main(int argc, char *argv[]) 
{
// __DATE__, __TIME__ are both static ?

		printf("\b\r%s %s\n", __DATE__, __TIME__);
		sleep(3);
		printf("\b\r%s %s", __DATE__, __TIME__);

	
	return 0;
}