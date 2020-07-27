#include <stdio.h>

void report_count();
void accumulate();

int count = 0;

int main(int argc, char *argv[]) 
{
	int value;
	register_t int i;
	puts("Enter a positive integer (0 to quit): ");
	while (scanf("%d", &value) && value > 0)
	{
		count ++ ;
		for (i = value; i >= 0; i--)
		{
			accumulate();
		}
		puts("Enter a positive integer (0 to quit): ");
	}
	
	report_count();
	return 0;
}

void accumulate()
{
	printf("Loop executed %d times", count);
}