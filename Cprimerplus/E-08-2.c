//use malloc()

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 32

struct name {
	char * first; 
	char * family;
	int letters ;
};

void getinfo(struct name *);
void setinfo(struct name *);
void showinfo(struct name *);
void cleaninfo(struct name *);

int main(int argc, char *argv[]) 
{
	struct name person;
	getinfo(&person);
	setinfo(&person);
	showinfo(&person);
	cleaninfo(&person);
	
	return 0;
}


void getinfo(struct name * n)
{
	char buf[LEN];
	fprintf(stdout, "Enter the first name : ");
	gets(buf);
	n->first = (char *)malloc(strlen(buf) + 1);
	strcpy(n->first, buf);
	fprintf(stdout, "Enter the family name : ");
	gets(buf);
	n->family = (char *)malloc(strlen(buf) + 1);
	strcpy(n->family, buf);
	
}


void setinfo(struct name * n)
{
	n->letters = strlen(n->first) + strlen(n->family);
}


void showinfo(struct name * n)
{
	fprintf(stdout, "%s %s, your name has %d letters.\n", n->first, n->family, n->letters);
	
}



void cleaninfo(struct name * n)
{
	free(n->first);
	free(n->family);
}