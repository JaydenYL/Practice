#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define answer_for_sets "Enter the number of sets (q to quit): "

int rollem(int);

int main(int argc, char *argv[]) 
{
	srand((unsigned int) time(0));
	int sides, dice, sets;
	
	printf(answer_for_sets);
	while(scanf("%d", &sets) ==1)
	{
		if (sets < 1)
		{
			printf("At least 1 sets.\n%s", answer_for_sets);
			continue;
		}
		
		printf("How many sides and how many dice?\n");
		scanf("%d %d", &sides, &dice);
		if (dice < 1 || sides < 2) {
			printf("Invalid dice or times");
			exit(EXIT_FAILURE);
		}
		
		printf("There are %d sets of %d %d-sided die throws:\n", sets, dice, sides);
		int i = 0;
		while (i++ < sets) 
		{
			printf("%-3d%c", rollem(sides), (i%8)?' ':'\n');
		}
		printf("\n%s", answer_for_sets);
	}
	
	return 0;
	
}

int rollem(int sides)
{
	return rand()%6 + 1;
}