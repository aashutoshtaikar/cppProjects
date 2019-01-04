#include<iostream>
#include<cstdint>
#include<memory>
#include<omp.h>
#include"Bitmap.h"
#include"MandelBrot.h"

#include"ZoomList.h"
#include"FractalCreator.h"
using namespace std;
using namespace caveofprogramming;

int main(){
    static const int WIDTH = 800;
    static const int HEIGHT = 600;

    double time0 = omp_get_wtime();
    FractalCreator fc(WIDTH,HEIGHT);
    fc.addZoom(Zoom(WIDTH/2,HEIGHT/2,4.0/WIDTH));
    fc.addZoom(Zoom(295,HEIGHT-202,0.1)); //init the scale in to >0
    fc.addZoom(Zoom(312,HEIGHT-304,0.1)); //init the scale in to >0
    fc.calculateIteration(WIDTH,HEIGHT);
    fc.drawFractal(WIDTH,HEIGHT);
    fc.writeBitmap("test");
    double time1 = omp_get_wtime();
    
    std::cout<<"Finished: " << time1-time0 << " seconds" <<endl;
    return 0;
}




