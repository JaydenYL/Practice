#include <stdio.h>
#include <string.h>

int main()
{
	char a[100];
	int start;
	int end;
	scanf("%s %d %d", a, &start, &end);
	long unsigned l = strlen(a);
	
	printf("%lu\n", l);
	
	int i = 0;
	char b[100] ;
	while (i < l)
	{
		b[i] = a[l-i];
		i ++;
	}
	printf("%s\n%s", a, b);
//	printf("%s", b);
	return 0;
}