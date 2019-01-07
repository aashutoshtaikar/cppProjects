#ifndef MANDELBROT_H_
#define MANDELBROT_H_

//stub for a fractal class - mandelbrot fractal
 //pass some co-ordinates - checks whether its in range -1 to 1
namespace caveofprogramming{

class MandelBrot{
public:
    static const int MAX_ITERATIONS = 1000;

    MandelBrot();
    
    static int getIterations(double x,double y);    //static as no instance vars

    virtual ~MandelBrot();
};    

}


#endif