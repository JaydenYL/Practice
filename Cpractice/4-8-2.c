#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char surname[20] , first[20];
	scanf("%s %s", first, surname);
	printf("surname\": %-20s\"\nfirstname: \": %-20s\"", surname, first);
}