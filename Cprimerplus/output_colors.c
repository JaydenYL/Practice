#include <stdio.h>
#define RED  	"\e[3;31m"
#define L_RED	"\e[3;31m"
#define NONE	"\e[0m"


int main(int argc, char *argv[]) 
{
	printf("[%2u]" RED "RED " L_RED "L_RED\n" NONE, __LINE__);
	return 0;
}

/*
https://www.cnblogs.com/clover-toeic/p/4031618.html

#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"

19 #define BOLD                 "\e[1m"
20 #define UNDERLINE            "\e[4m"
21 #define BLINK                "\e[5m"
22 #define REVERSE              "\e[7m"
23 #define HIDE                 "\e[8m"
24 #define CLEAR                "\e[2J"
25 #define CLRLINE              "\r\e[K" //or "\e[1K\r"