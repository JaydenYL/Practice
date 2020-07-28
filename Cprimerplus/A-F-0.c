# include <stdio.h>

int main(void)
{

	
	int zippo[4][3] = {{2,4,0}, {6,8, 1}, {1, 3, 2}, {5, 7, 3}};
//	zippo[0][0] = 4;
	printf("zippo = %p,  zippo + 1 = %p, zippo[0] = %p\n", zippo, zippo + 1, zippo[0]);
	printf("%d\n", zippo == zippo[0]);
	printf("%d\n", *zippo == zippo[0]);
	printf("%d\n", zippo + 2 == zippo[2]);
	printf("%d\n", *(zippo[0]));
	return 0;


}