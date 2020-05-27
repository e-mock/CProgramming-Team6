#include <stdio.h>


int Run_motor(int);

int select;

int rpm ,speed1 = 100,speed2 = 100;

int Run_motor(select)
{
	switch(select)
	{
	case 1:
		if(speed1<=1500)
		{
			speed1 = speed1 + 100;
		}
		rpm = speed1;
		break;

	case 2:
		if(speed2<=1500)
		{
			speed2 = speed2 + 100;
		}
		rpm = speed2;
		break;

	default:
		break;
	}
	return rpm;
}

