#include <stdio.h>
int main(void)
{
	float weight;
	float value;
	printf("Are you worth your weight in rhodium?\n");
	printf("Let's check it out.\n");
	printf("Please enter your weight in pounds:");
	scanf("%f", &weight);
	value = 770*14.5833*weight;
	printf("%.4f\n", value);
	return 0;
}