#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) {
	int j = 0;
	#pragma omp parallel 
		#pragma omp for
		for ( j = 0; j < 4; j++ ){
			printf("j = %d, ThreadId = %d\n", j, omp_get_thread_num());
		}
}
	
