#include <stdio.h>
#define LEN 50


struct funds{
	char bank[LEN];
	double bankfund;
	char save[LEN];
	double savefund;
};


double sum(const struct funds);


int main(int argc, char *argv[]) 
{
	struct funds fd = {
		"bank of China",
		10000,
		"bank fo australia",
		100000
	};
	printf("The sum : %.2lf\n", sum(fd));
	
	
	return 0;
	
}

double sum(const struct funds  money)
{
	return (money.bankfund + money.savefund);
}