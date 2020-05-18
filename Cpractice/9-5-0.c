#include <stdio.h>

void mikado(int);

int main(int argc, char *argv[]) 
{
	int pooh = 2, bah = 5;
	printf("In main() , pooh = %d, &pooh = %p\n", pooh, &pooh );
	printf("In main() , bah = %d, &bah = %p\n", bah, &bah );
	mikado(pooh);
}


void mikado(int a)
{	
	int pooh = 10;
	printf("In mikado(), a = %d, &a = %p\n", a, &a);
	printf("In mikado(), pooh = %d, &pooh = %p\n", pooh, &pooh);
	
}