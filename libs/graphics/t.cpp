#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <graphics.h>


/*
sin(double) sinf(float), sinl(long double)
*/
void semicircles1();

int main()
{
	//clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	semicircles1();
	delay(7000);
	closegraph();

	return 0;
}

void semicircles1()
{
	int angle = 0;
	double x,y;
 	line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
 	/* generate a sine wae */
 	for(x = 0; x < getmaxx(); x+=6) 
 	{
 		 /* calculate y value given x */
     	y = 50*sin(angle*3.141/180);
		y = getmaxy()/2 - y;
		if (y<getmaxy()/2)
		{
			outtextxy(x,y,"*");

		}
		angle+=5;
		
		//outtextxy(getmax(),getmaxy(),"*");
 	}
 	
 	for(x = 6; x < getmaxx(); x+=6) 
 	{
 		 /* calculate y value given x */
     	y = 50*sin(angle*3.141/180);
		y = getmaxy()/2 - y;
		if (y<getmaxy()/2 )
		{
			outtextxy(x,y,"*");
		}
		angle+=5;
 	}
}
