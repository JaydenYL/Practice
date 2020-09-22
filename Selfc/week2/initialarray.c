#include <stdio.h>

int at[100]; // all zero if initialized as global

int main(int argc, char *argv[]) {
	int arr[100] ;			//random integer if in brackets
	for(int i=0; i < 100; i++){
		printf("%d %d\n", arr[i], at[i]);
	}
	return 0;
	
}