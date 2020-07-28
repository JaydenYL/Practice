#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollem(int);

int main(int argc, char *argv[]) 
{
	srand((unsigned int) time(0));
	printf("Enter the number of sides: ");
	int sides, dice, times, roll_count;
	scanf("%d", &sides);
	if (sides < 2)
	{
		printf("At least 2 sides.\n");
		exit(EXIT_FAILURE);
	}
	printf("How many dice and how many times?\n");
	scanf("%d %d", &dice, &times);
	
	if (dice < 1 || times < 1) {
		printf("Invalid dice or times");
		exit(EXIT_FAILURE);
	}
	roll_count = dice * times;
	printf("There are %d sets of %d %d-sided die throws:\n", roll_count, dice, times);
	int i = 0;
	while (i++ < roll_count) 
	{
		printf("%-3d%c", rollem(sides), (i%8)?' ':'\n');
	}
	
	return 0;
	
}

int rollem(int sides)
{
	return rand()%6 + 1;
}