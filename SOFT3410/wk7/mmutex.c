#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <time.h>

#define N_THREAD 8
#define MAX_LEN 12800000

typedef struct Argu {
	int* cursor;
	int* array;
	int length;
	long* res;
//	sem_t* available;
} Argu;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* cal(void* hh) {
	Argu* argu = (Argu*) hh;
	int* cur = argu->cursor;
	int* ary = argu->array;
	int len = argu->length;
	
	register int tmp_cur;
	register int res = 0;
	while (1) {
		pthread_mutex_lock(&mutex);
		if (*cur >= len) {
			pthread_mutex_unlock(&mutex);
			break;
		} else {
			tmp_cur = *cur;
			++ *cur;
		}
		pthread_mutex_unlock(&mutex);
		
		for (int i = 0, l = ary[tmp_cur]; i < l; i++) {
			res += ary[i];
		}
	}
	pthread_mutex_lock(&mutex);
	*(argu->res) += res;
	pthread_mutex_unlock(&mutex);

	return NULL;
}


int main(int argc, char *argv[]) {
	srand(1);
	int* ary = (int*) malloc(sizeof(int)*MAX_LEN);
	for (int i = 0; i < MAX_LEN; i++) {
		ary[i] = rand() %128 + 100;
	}

	long res = 0;
	int cur = 0;
	Argu parameter = {
		.cursor = &cur,
		.array = ary,
		.length = MAX_LEN,
		.res = &res,
	};
	pthread_t* thread_pool = (pthread_t*)malloc(sizeof(pthread_t) * N_THREAD);
	
	clock_t start_t, end_t;

	start_t = clock();
	for (int i = 0; i < N_THREAD; i++) {
		pthread_create(thread_pool+i, NULL, cal, &parameter);
	}
	
	for (int i = 0; i < N_THREAD; i++) {
		pthread_join(*(thread_pool+i), NULL);
	}
	end_t = clock();
	
	fprintf(stdout, "TIME : %lf\n", (float)(end_t - start_t)/CLOCKS_PER_SEC);
	printf("%ld\n", res);
	return 0;
}
