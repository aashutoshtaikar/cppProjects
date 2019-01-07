#include<iostream>
#include<omp.h>

#include"FractalCreator.h"
#include"Rgb.h"

using namespace std;
using namespace caveofprogramming;

int main(){

    const int HEIGHT = 600;
    double time0 = omp_get_wtime();
    FractalCreator fc(800,600);
    fc.addZoom(Zoom(295,202,0.1)); //init the scale in to >0
    fc.addZoom(Zoom(312,304,0.1)); //init the scale in to >0    //(HEIGHT-)fixed in ZoomList.cpp
    fc.run("test");
    double time1 = omp_get_wtime();
    
    std::cout<<"Finished: " << time1-time0 << " seconds" <<endl;
    return 0;
}




