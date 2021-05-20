#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	
	char c;

	while (read(STDIN_FILENO, &c, 1) != 0) {
		write(STDOUT_FILENO, &c, 1);
	}
}