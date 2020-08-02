#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	char * filepath;
	FILE * fp;
	fp = (argc == 2) ? fopen(argv[1], "r") : stdin ;
	double sum = .0, tmp = .0;
	int count = 0, num;
	if (argc != 2)
		puts("Enter numbers (q to finish):");
	while((num = fscanf(fp, "%lf", &tmp)) > 0){
		sum += tmp;
		count ++;
	}
	fclose(fp);
	printf("The average of array is %.3lf\n", sum/count);
	
	return 0;
}