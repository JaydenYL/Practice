#include <stdio.h>


void display(char cr, int lines, int width);

int main(int argc, char *argv[]) 
{
	int l, r;
	int ch;
	while ((ch = getchar())!= '\n')
	{
		scanf("%d %d", &r, &l);
		display(ch, l, r);
	}
}



void display(char cr, int lines, int width ) 
{
	for (int i = 0; i < lines; i++) 
	{
		for ( int j = 0; j < width; j++) putchar(cr);
		putchar('\n');
	}
}