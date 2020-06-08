#include <stdio.h>

//void jolly();
//void deny();


int main(int argc, char *argv[]) {
	void jolly();
	void deny();
	for (int i = 0; i < 3; i ++) {
		jolly();
	}
	deny();
}



void jolly(){
	printf("For he's a jooly good fellow!\n");
}
void deny(){
	printf("Which nobody deny!\n");
}