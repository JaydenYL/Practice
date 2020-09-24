#include <stdio.h>

typedef struct Batter batter;

struct Batter{
	char  firstname[32];
	char  lastname[32];
	int runs;
};

int main(int argc, char *argv[]) 
{
	batter batmans[10];
	for(int i = 0; i < 10; i++){
		scanf("%s %s %d", batmans[i].firstname, batmans[i].lastname, &batmans[i].runs);
	}
	for(int i = 0; i < 10; i++){
		printf("%d. %c. %s: ", i+1, batmans[i].firstname[0], batmans[i].lastname);
		if(batmans[i].runs){
			printf("%d\n", batmans[i].runs);
		}
		else 
		{
			printf("Duck\n")	;
		}
	}
	
	return 0;
}