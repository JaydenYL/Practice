#include <stdio.h>
#include <stdlib.h>
#include "C-04-3.h"

int roll_count = 0;

static int rollem(int sides)
{
	roll_count ++;
	return rand()%sides + 1;
}

int roll_n_dice(int dice, int sides)
{
	if (dice < 1){
		printf("Need at least 1 dice.\n");
		return -2;
	}
	if (sides < 2){
		printf("Nees at leat 2 sides.\n");
		return -1;
	}
	int total = 0;
	for (int i = 0; i < dice; i++)
	{
		total  += rollem(sides);
	}
	return total;
}

