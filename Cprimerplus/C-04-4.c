// many dice

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "C-04-3.h"

int main(int argc, char *argv[]) 
{
	int dice, sides, roll;
	srand((unsigned int) time(0));
	printf("Enter the number of sides per die (0 to quit): ");
	while (scanf("%d", &sides) && sides > 0 )
	{
		printf("How many dice ?  -- ");
		scanf("%d", &dice);
		roll = roll_n_dice(dice, sides);
		printf("You have rolled a %d using %d %d-sides dice.\n", roll, dice, sides);
		printf("Enter the number of sides per die (0 to quit): ");
	}
	printf("The rollem funciton has been called %d times.\n", roll_count);
	printf("GOOD FORTUNE TO YOU.\n");
	
	reutrn 0;
}