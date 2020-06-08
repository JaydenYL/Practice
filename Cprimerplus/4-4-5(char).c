#include <stdio.h>

int main(int argc, char *argv[]) {
	char s[100];
	char x = '\0';
	printf("%p\n", s);
	printf("%d \n", x);
	char ch;
	scanf("%c",&ch);// %前面有空格读取非空第一个字符；无空格读取第一个字符
	printf("%c*",ch);
}