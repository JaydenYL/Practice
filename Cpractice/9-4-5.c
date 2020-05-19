#include <stdio.h>
#include "hotel.h"

// when compile this file :	gcc 9-4-5.c hotel.c std=c99
// do not forget the "hotel.c",  it is not like java
// and cannot use :  gcc *.c	, because it will rasie duplicate symbols -- it is the main function, 
// an project can just have one main function. 

int main(int argc, char *argv[]) 
{
	int nights, code;
	double hotel_rate;
	while ((code = menu()) != QUIT)
	{
		switch (code) 
		{
			case 1: hotel_rate = HOTEL1;
					break;
			case 2: hotel_rate = HOTEL2;
					break;
			case 3: hotel_rate = HOTEL3;
					break;
			case 4: hotel_rate = HOTEL4;
					break;
			default:hotel_rate = 0.0;
					printf("Oops!\n");
					break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
		
	}
	printf("Thank you. and goodbye.\n");
	return 0;
	
}
