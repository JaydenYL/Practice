#include <stdio.h>

void func();

extern void func();

void func(){
	printf("hello world by func()\n");
}