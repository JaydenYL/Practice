#include <stdio.h>
int main(int argc, char const *argv[])
{
	int days, years;
	scanf("%d",&years);
	days = 365*years;
	printf("%d\n", days);
	return 0;
}