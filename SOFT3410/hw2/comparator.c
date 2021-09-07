#include <stdio.h>
#include <ctype.h>


int comparator(const char* str_1, const char* str_2, int asc) {
	// int i = 0;
	// for (; str_1[i] && str_2[i] && i < 127; i++) {
	// 	if (str_1[i] < str_2[i]) {
	//         return asc;
	// 	} else if (str_1[i] > str_2[i]) {
	//         return -asc;
	// 	}
	// }
	// return (!str_1[i] - !str_2[i])*asc;
	int ret = 0;
	while (!(ret = *(unsigned char *)str_1 - *(unsigned char *)str_2) && *str_2) {
		++str_1, ++str_2;
	}
	if (ret == 0) return 0;
	return (ret > 0) ? -asc : asc;
	
}


int main(int argc, char *argv[]) {
	printf("%d\n", comparator("", "abc", 1));
}

