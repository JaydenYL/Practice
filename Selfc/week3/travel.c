#include <stdio.h>

# define MPH 0.621371

int main(int argc, char *argv[]) 
{
	double speed;
	double hours;
	
	puts("What's your current speed(km/h): ");
	scanf("%lf", &speed);
	puts("How many hours are you travelling for: ");
	scanf("%lf", &hours);
	printf("You will cover : %.2lf km ( %.2lf mi)\n", speed*hours, speed*hours*MPH);
	printf("While traveling at %.2lf km/h ( %.2lf mph)\n", speed, MPH * speed);
	return 0;
	
}