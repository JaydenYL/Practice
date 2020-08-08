#include <stdio.h>
#include <string.h>
#define LEN 32

struct name {
	char first[LEN];
	char family[LEN];
	int letters;
};

void getinfo(struct name *);
void setinfo(struct name *);
void showinfo(struct name *);


int main(int argc, char *argv[]) 
{
	
	struct name person;
	getinfo(&person);
	setinfo(&person);
	showinfo(&person);
	
	return 0;
}




void getinfo(struct name * n)
{
	printf("Enter your first name: ");
	gets(n->first);
	printf("Enter your family name: ");
	gets(n->family);
}



void setinfo(struct name * n)
{
	n->letters = strlen(n->first) + strlen(n->family);
}



void showinfo(struct name * n)
{
	fprintf(stdout, "%s %s, your name has %d letters\n", n->first, n->family, n->letters);
}