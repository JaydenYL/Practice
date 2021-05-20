#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char msg[100] = {0};
	int p = open("my_fifo", O_RDWR);
	read(p, msg, 100);
	close(p);
	printf("%s\n", msg);
	
	return 0;
}