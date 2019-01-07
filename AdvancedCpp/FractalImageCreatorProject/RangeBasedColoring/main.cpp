#include<iostream>
//#include<omp.h>

#include"FractalCreator.h"
#include"Rgb.h"

using namespace std;
using namespace caveofprogramming;

int main(){
    
   double time0 = omp_get_wtime();
    
    FractalCreator fc(800,600);

    fc.addRange(0.0,Rgb(50,0,255));
    fc.addRange(0.3,Rgb(255,100,0));
    fc.addRange(0.5,Rgb(255,150,0));
    fc.addRange(1.0,Rgb(255,255,255));

    fc.addZoom(Zoom(295,202,0.1)); //init the scale in to >0
    //fc.addZoom(Zoom(312,304,0.1)); //init the scale in to >0    //(HEIGHT-)fixed in ZoomList.cpp
    fc.run("test");
    
   double time1 = omp_get_wtime();
    
    std::cout<<"Finished: " << time1-time0 << " seconds" <<endl;
    return 0;
}




