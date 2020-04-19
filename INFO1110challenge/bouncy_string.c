// Author: LIU YU
// 2019-9-14 15:44 AEST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		printf("Invalid arguments length\n");
		return 0;
	}
	long unsigned l = strlen(argv[1]);
	int start = atoi(argv[2]);
	int end = atoi(argv[3]);
	if ( (start < 0) || (start >= l) || (argv[2][0] < 48 ) || (argv[2][0] > 57))
	{
		printf("Invalid start position\n");
		return 0;
	}
	if (end < 0)
	{
		printf("Invalid iteration count\n");
		return 0;
	}
	int position;
	for(int i = 0; i <= end; i++)
	{
		if (l == 1)
		{
			printf("%s", argv[1]);
		}
		else
		{			
			position = (i + start) % (l + l - 2);
			if (position < l) printf("%c", argv[1][position]);
			else if (position < 2*l - 1) printf("%c", argv[1][2*l - 2- position]);
		}
	}
	printf("\n");
	return 0;
}