// Bad exmaple
// these function doesnot work

#include <stdio.h>
#include <string.h>
#define LEN 32

struct name {
	char first[LEN];
	char family[LEN];
	int letters ;
};

void getinfo(struct name );
void setinfo(struct name );
void showinfo(struct name );


int main(int argc, char *argv[]) 
{
	
	struct name person;
	getinfo(person);
	setinfo(person);
//	showinfo(person);
	
	printf("%d\n", person.letters);
	person.letters = 999;
	printf("%d\n", person.letters);
	
	return 0;
}




void getinfo(struct name  n)
{
	printf("Enter your first name: ");
	gets(n.first);
	printf("Enter your family name: ");
	gets(n.family);
}



void setinfo(struct name  n)
{
	int x  = strlen(n.first) + strlen(n.family);
	printf("%d\n",x);
	n.letters = x;
}



void showinfo(struct name n)
{
	fprintf(stdout, "%s %s, your name has %d letters\n", n.first, n.family, n.letters);
}