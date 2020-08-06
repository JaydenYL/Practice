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
	struct name n;
	char favfood[LEN];
	char job[LEN];
	float income;
};