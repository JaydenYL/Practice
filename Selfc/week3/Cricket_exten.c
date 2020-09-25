#include <stdio.h>
#include <stdlib.h>

char * getString(FILE * );

typedef struct Batter batter;

struct Batter{
	char  * firstname;
	char  * lastname;
	int runs;
};


// line 20 - 25 : assign the address of to char * to char **

int main(int argc, char *argv[]) 
{
	batter batmans[10];
// -----
	char * tmp[20];
	for(int i = 0; i < 10; i++){
		batmans[i].firstname = getString(stdin);
		batmans[i].lastname  = getString(stdin);
// -----
		scanf("%d", & batmans[i].runs);
		while(getchar() == '\n') break;
	}
	
//	printf("%c", *batmans[0].firstname[0]);
	for(int i = 0; i < 10; i++){
		printf("%d. %c. %s: ", i+1, batmans[i].firstname[0], batmans[i].lastname);
		if(batmans[i].runs){
			printf("%d\n", batmans[i].runs);
		}
		else 
		{
			printf("Duck\n");
		}
	}
	
	return 0;
}

char * getString(FILE * fp)
{
	int len = 8;
	size_t i = 0;
	char * str = realloc(NULL, sizeof(char)*len);
	char ch;
	while((ch = fgetc(fp))!=EOF  && ch != ' '){
		str[i++] = ch;
		if(i == len){
			str = realloc(str, sizeof(char)*(len+=8));
			if (!str) return  str;
		}
	}

	str[i++] = 0;
	return (char *)realloc(str, sizeof(char)*i);
	
}