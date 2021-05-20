#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	int res = mkdir("my_dir", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	printf("%d\n", res);
	res = mkdir("my_dir/inside", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	printf("%d\n", S_IRWXU);
	return 0;
}