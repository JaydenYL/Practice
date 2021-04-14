#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

void show_time(int n){
	time_t t;
	time(&t);
	printf("%s",ctime(&t));
}

int main(){
	
	signal(SIGURG, show_time);
	getchar();
	return 0;
	
}