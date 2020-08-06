#include <stdio.h>
#define LEN 32

const char * msg[5] = {
	"Thank you for wonderful evening",
	"You certianly prove that a",
	"is a special kind of guy. We must get together",
	"over a delicious",
	"and have a fews"
};

struct name {
	char first[LEN];
	char family[LEN];
};


struct guy{
	struct name fullname;
	char favfood[LEN];
	char job[LEN];
	float income;
};


int main(int argc, char *argv[])
{
	struct guy fellow = {
		{"Jayden", "YU"},
		"grilled samon",
		"programmer",
		1e5
	};
	
	printf("Full name : %s %s\n", fellow.fullname.first, fellow.fullname.family);
	printf("Job : %s\n", fellow.job);
	printf("INCOME :\e[5;31m %f\e[0m", fellow.income);
	if (fellow.income >= 100000)
		printf("!!!\n");
	else if (fellow.income >= 50000)
		printf("!!\n");
	else 
		printf("!\n");
	
	
	return 0;
}