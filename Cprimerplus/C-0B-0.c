#include <stdio.h>

void critic(int *);

int main(int argc, char *argv[]) 
{
	int  unit[1];
	printf("How many pounds to a frikin of butter ?\n ");
	scanf("%d", unit);
	while(*unit != 56)
	{
		critic(unit);
	}	
	printf("You must have look it up!\n");
	
	return  0;
}


void critic(int * num)
{
	printf("Unluckily, chummy, try again.\n");
	scanf("%d", num);
}