#include <stdio.h>
#define  MAXTITL  64
#define  MAXAUTH  64
#define  MAXBOKS  64

struct book{
	char  title[MAXTITL];
	char  auth[MAXAUTH];
	float value;
};


int main(int argc, char *argv[]) 
{
	struct book library[MAXBOKS];
	int count = 0, idx;
	
	printf("Enter the book title : \n");
	printf("Press [ENTER] at the start of line to stop.\n");
	while (count < MAXBOKS && gets(library[count].title) != NULL && library[count].title[0]) 
	{
		printf("Now enter the auhtor :");
		gets(library[count].auth);
		printf("Now enter the price :");
		scanf("%f", &library[count++].value);
		while (getchar() != 10) {}
		if (count < MAXBOKS)
			printf("Enter the next line :");
	}
	
	if (count > 0)
	{
		printf("Here is the list of your books :\n");
		for (idx = 0; idx < count ; idx ++)
		{
			printf("\e[3;33m%s\e[0m by \e[0;31m%s \e[0m: \e[0;30m$%.2f[0m\n",library[idx].title, library[idx].auth , library[idx].value);  
		}
	}
	else {
		printf("No books , so bad\n");
	}
	
	
	return 0;
}