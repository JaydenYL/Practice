#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	char * filepath;
	if (argc == 2){
		filepath = argv[1];
		FILE * fp = fopen(filepath, "r");
	}
	else {
//		filepath = (char *)malloc((unsigned int)sizeof(char)*50);
//		puts("Enter the file name: ");
//		scanf("%s", filepath);
		filepath =stdin;
	}
	double sum = .0, tmp = .0;
	int count = 0, num;
	while((num = fscanf(filepath, "%lf", &tmp)) != EOF && num != 0){
		sum += tmp;
		count ++;
	}
	
	printf("The average of array is %lf", sum/count);
	
	return 0;
}