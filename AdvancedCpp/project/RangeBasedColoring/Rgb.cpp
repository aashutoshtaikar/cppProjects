#include "Rgb.h"
namespace caveofprogramming{

Rgb::Rgb(double r,double g, double b):red(r),green(g),blue(b){}

Rgb operator-(const Rgb &first,const Rgb &second){
    return Rgb(first.red-second.red,first.green-second.green,first.blue-second.blue);
}

}