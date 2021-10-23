#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define MAX_LEN 12800000

int main(int argc, char *argv[]) {
	srand(1);
	int* ary = (int*) malloc(sizeof(int)*MAX_LEN);
	for (int i = 0; i < MAX_LEN; i++) {
		ary[i] = rand() %128 + 100;
	}

	register long res = 0;

	
	clock_t start_t, end_t;
	start_t = clock();


	for (int i = 0; i < MAX_LEN; i++) {
		for (int j = 0, l = ary[i]; j < l; j ++) {
			res += ary[j];
		}
	}
	
	
	end_t = clock();
	fprintf(stderr, "%.6f\n", (float)(end_t - start_t)/CLOCKS_PER_SEC);
	printf("%ld\n", res);
	return 0;
}
