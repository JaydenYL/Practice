#include <stdio.h>

#define MAXNUM(X, Y) ((X > Y) ? X : Y)

int main(int argc, char *argv[]) 
{
	int x, y;
	puts("Enter tow number: ");
	scanf("%d %d", &x, &y);
	
	printf("%d\n", MAXNUM(x, y));
	
	return 0;
}