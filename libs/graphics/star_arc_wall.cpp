#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <graphics.h>


/*
sin(double) sinf(float), sinl(long double)
*/

int main()
{
	//clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int angle = 0;
	double x,y;
 line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
 /* generate a sine wave */
 
 for(x = 0; x < getmaxx(); x+=3) {
 
     /* calculate y value given x */
     y = 50*sin(angle*3.141/180);
     y = getmaxy()/2 - y;
 
     /* color a pixel at the given position */
  putpixel(x, y, 15);
  
 
  /* increment angle */
  angle+=5;
 }
 
 //getch();
 
 /* deallocate memory allocated for graphics screen */

	//sinewave();
	delay(7000);
	closegraph();

	return 0;
}

/*void sinewave()
{
	float x=0,y=0,n=6.3,r=0.2,k=150,t=0;
	char mk = 
}
*/

