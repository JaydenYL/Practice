#include <stdio.h>

enum TYPE 
{
	FIRE, WATER, FLYING, ROCK, ELECTRIC 
};

struct pokemon {
	const char* name;
	enum TYPE type; 
};


int main(int argc, char *argv[]) {
	struct pokemon pikachu = { .type = ELECTRIC, .name = "Pikachu" };
	printf("sizeof(enum TYPE): %lu\n", sizeof(enum TYPE));
	printf("%d %s\n", pikachu.type, pikachu.name);
	return 0;
}