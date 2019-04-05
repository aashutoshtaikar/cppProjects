#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

/*
sin(double) sinf(float), sinl(long double)
*/
void firstrow(double gx, double gy, int NumArcs, int radius,float height);
void secondrow(double gx, double gy, int NumArcs, int radius);
void thirdrow(double gx, double gy, int NumArcs, int radius);

int main()
{
    //clrscr();
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    double tgx=(getmaxx()/3);
    double tgy=(getmaxy()/3);
    firstrow(tgx,tgy,5,50,-40); //  num of arcs 1-5  and radius 5 - 50 
    secondrow(tgx,tgy,4,40); //  num of arcs 1-5  and radius 5 - 50 
    thirdrow(tgx,tgy,4,40);  //  num of arcs 1-5 and radius 5 - 50 
    delay(7000);
    closegraph();

    return 0;
}

void firstrow(double gx, double gy, int NumArcs, int radius, float height)
{
    //int angle = 0;
    //double x,y;

    //first row arcs
    for (int i=NumArcs;i!=0;i--)
    {
    arc((i*gx)/2,(1*gy)/2,180,360,radius);
    }

     //first row lines below arcs
    for (int i=NumArcs;i!=0;i--)
    {
        line(((i*gx)/2)-radius,(1*gy)/2,((i*gx)/2)-radius,height+((2*gy)/2));
        line(((i*gx)/2)+radius,(1*gy)/2,((i*gx)/2)+radius,height+((2*gy)/2));
        line(((i*gx)/2)-radius,height+((2*gy)/2),((i*gx)/2)+radius,height+((2*gy)/2));
    }
}

void secondrow(double gx, double gy, int NumArcs, int radius)
{
    //int angle = 0;
    //double x,y;

    //first row
    for (int i=NumArcs;i!=0;i--)
    {
    arc((i*gx)/2,(3*gy)/2,180,360,radius);
    }

    for (int i=NumArcs;i!=0;i--)
    {
        line(((i*gx)/2)-radius,(3*gy)/2,((i*gx)/2)-radius,(4*gy)/2);
        line(((i*gx)/2)+radius,(3*gy)/2,((i*gx)/2)+radius,(4*gy)/2);
        line(((i*gx)/2)-radius,(4*gy)/2,((i*gx)/2)+radius,(4*gy)/2);
    }
}

void thirdrow(double gx, double gy, int NumArcs, int radius)
{
    //int angle = 0;
    //double x,y;

    //first row
    for (int i=NumArcs;i!=0;i--)
    {
    arc((i*gx)/2,(5*gy)/2,180,360,radius);
    }

    for (int i=NumArcs;i!=0;i--)
    {
        line(((i*gx)/2)-radius,(5*gy)/2,((i*gx)/2)-radius,(6*gy)/2);
        line(((i*gx)/2)+radius,(5*gy)/2,((i*gx)/2)+radius,(6*gy)/2);
        line(((i*gx)/2)-radius,(6*gy)/2,((i*gx)/2)+radius,(6*gy)/2);
    }
}

/* backup
void firstrow()
{
    //int angle = 0;
    //double x,y;

    //first row
    arc((1*gx)/2,(1*gy)/2,180,360,40);
    arc((2*gx)/2,(1*gy)/2,180,360,40);
    arc((3*gx)/2,(1*gy)/2,180,360,40);
    arc((4*gx)/2,(1*gy)/2,180,360,40);
    arc((5*gx)/2,(1*gy)/2,180,360,40);
}

void secondrow()
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

void thirdrow()
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
*/
