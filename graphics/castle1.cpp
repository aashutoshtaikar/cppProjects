#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

/*
sin(double) sinf(float), sinl(long double)
*/
void firstrow(double gx, double gy);
void secondrow(double gx, double gy);
void thirdrow(double gx, double gy);

int main()
{
	//clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	double tgx=(getmaxx()/3);
	double tgy=(getmaxy()/3);

	firstrow(tgx,tgy);	
	secondrow(tgx,tgy);
	thirdrow(tgx,tgy);	
	delay(7000);
	closegraph();

	return 0;
}

void firstrow(double gx, double gy)
{
	//int angle = 0;
	//double x,y;

	//first row
	arc((1*gx)/2,(1*gy)/2,180,360,40);
	arc((2*gx)/2,(1*gy)/2,180,360,40);
	arc((3*gx)/2,(1*gy)/2,180,360,40);
	arc((4*gx)/2,(1*gy)/2,180,360,40);
	arc((5*gx)/2,(1*gy)/2,180,360,40);

	line(((1*gx)/2)-40,(1*gy)/2,((1*gx)/2)-40,(2*gy)/2);
	line(((1*gx)/2)+40,(1*gy)/2,((1*gx)/2)+40,(2*gy)/2);
	line(((1*gx)/2)-40,(2*gy)/2,((1*gx)/2)+40,(2*gy)/2);

	line(((2*gx)/2)-40,(1*gy)/2,((2*gx)/2)-40,(2*gy)/2);
	line(((2*gx)/2)+40,(1*gy)/2,((2*gx)/2)+40,(2*gy)/2);
	line(((2*gx)/2)-40,(2*gy)/2,((2*gx)/2)+40,(2*gy)/2);

}

void secondrow(double gx, double gy)
{
	//int angle = 0;
	//double x,y;

	//second row
	arc((1*gx)/2,(3*gy)/2,180,360,40);
	arc((2*gx)/2,(3*gy)/2,180,360,40);
	arc((3*gx)/2,(3*gy)/2,180,360,40);
	arc((4*gx)/2,(3*gy)/2,180,360,40);
	arc((5*gx)/2,(3*gy)/2,180,360,40);
}

void thirdrow(double gx, double gy)
{
	//int angle = 0;
	//double x,y;

	//third row
	arc((1*gx)/2,(5*gy)/2,180,360,40);
	arc((2*gx)/2,(5*gy)/2,180,360,40);
	arc((3*gx)/2,(5*gy)/2,180,360,40);
	arc((4*gx)/2,(5*gy)/2,180,360,40);
	arc((5*gx)/2,(5*gy)/2,180,360,40);
}

