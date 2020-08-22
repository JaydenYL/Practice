#include <stdio.h>
#include <math.h>

typedef struct polar
{
	double magnitude;
	double angle;
} POLAR;

typedef struct coordinate
{
	double x;
	double y;
} COOR ;

POLAR coor_to_polar(COOR);

int main(int argc, char *argv[]) 
{
	COOR cdt;
	POLAR plr;
	puts("Please enter the x , y coordinates(q to quit): ");
	while (scanf("%lf %lf", &cdt.x, &cdt.y) == 2)
	{
		plr = coor_to_polar(cdt);
		printf("The polar coordinates of cdt is:\n\
angle: %lf\nmagnitude: %lf\n", plr.angle, plr.magnitude);
		puts("Please enter the x , y coordinates(q to quit): ");
	}
	puts("Bye\n");
	return 0;
}

POLAR coor_to_polar(COOR c)
{
	POLAR p;
	if (!c.x && !c.y)
		p.magnitude = (p.angle = 0);
	else 
	{ 
		p.magnitude = sqrt(c.x*c.x + c.y*c.y);
		p.angle = atan2(c.x, c.y);
	}
	return p;
}