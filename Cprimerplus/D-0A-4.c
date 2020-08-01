#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	char * filepath;
	FILE * fp;
	if (argc == 2){
		filepath = argv[1];
		fp = fopen(filepath, "r");
	}
	else {
//		filepath = (char *)malloc((unsigned int)sizeof(char)*50);
//		puts("Enter the file name: ");
//		scanf("%s", filepath);
		fp =stdin;
	}
	double sum = .0, tmp = .0;
	int count = 0, num;
	if (argc != 2)
		puts("Enter numbers (q to finish):");
	while((num = fscanf(fp, "%lf", &tmp)) != EOF && num != 0){
		sum += tmp;
		count ++;
	}
	
	printf("The average of array is %.3lf\n", sum/count);
	
	return 0;
}