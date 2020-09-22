#include <stdio.h>

enum weekday{
	mon, tue, wed, thu, fri, sat, sun
};

int main(int argc, char *argv[]) {
	enum weekday day = sun;
	printf("%u\n", day);
	printf("%u\n", ++day);
	printf("%u\n", ++day);
	return 0;
}

