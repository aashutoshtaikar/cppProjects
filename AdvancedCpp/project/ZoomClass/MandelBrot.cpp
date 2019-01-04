#include"MandelBrot.h"
#include<complex>
using namespace std;

namespace caveofprogramming{

MandelBrot::MandelBrot(){}

int MandelBrot::getIterations(double x,double y){
    complex<double> z = 0;  //sets both pair of nums to 0
    complex<double> c(x,y); //set by using constructor

    int iterations = 0; 

    while(iterations<MAX_ITERATIONS){   //should not go to infinity
        z = z*z +c;    // 
        if(abs(z)>2){
            break;
        }   //else if below 2 co-ordinates belongs to the part of the mandelbrot set
        iterations++;
    }
    return iterations;
}

MandelBrot::~MandelBrot(){}

}