#include <stdio.h>

int zero_or_one(int num, int bit);

int main(int argc, char *argv[]) 
{
	
	
	return 0;
}

int zero_or_one(int num, int bit)
{
	num >>= bit;
	return num & 1;
}