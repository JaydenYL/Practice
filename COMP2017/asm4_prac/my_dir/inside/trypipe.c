#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int pipefd[2] = {0};
	int fd_wr = open("inin", O_RDWR);
	int fd_rd = open("outout", O_RDWR);
	pipefd[0] = fd_wr;
	pipefd[1] = fd_rd;
	if (pipe(pipefd) < 0) {
		perror("Unable to create pipe");
	}
	char c; 
	read(pipefd[1], &c, 1);
	write(STDOUT_FILENO, &c, 1);
	
	return 0;
}