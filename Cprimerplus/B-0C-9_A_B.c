#include <stdio.h>

size_t  strlength(char *);
char * question_A(char *);
void  question_B(char *);
int  str_compare(char * , char *);


int main(int argc, char *argv[]) 
{
	char str[] = "hello world";
	printf("%zu\n", strlength(str));
	printf("%d\n", str_compare("hel", "hel"));
	printf("address of str:       %p \n\
answer of question A: %p", str, question_A(str));
	question_B(str);
	return 0;
}


size_t strlength(char * str)
{
	size_t count = 0;
	for ( ; str[count]; count ++);
	return count ; 
}


char * question_A(char * str)
{
	while (str) 
	{
		if (*str == ' ') return str ;
		str++;
	}
	return NULL;
}


void question_B(char * answer)
{
	puts("guess the answer : ");
	char input[100];
	while (!str_compare(answer, gets(input)))
	{
		puts("not correct, enter the answer again: ");
	}
	printf("correct, congratualtions!\n");
}


int str_compare(char * str1, char * str2)
{
	for ( ; *str1 && *str2 ; str1++, str2++)
	{
		if ( str1[1]  == str2[1] ) {
			if (str1[1] == '\0') return 1;
		}
		else return 0;
	}
	
	return 0;
}