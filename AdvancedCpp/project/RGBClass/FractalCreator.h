
#if !defined(FractalCreator_H_)
#define FractalCreator_H_
#include <iostream>
#include<string>
#include<math.h>
#include<omp.h>
#include"Zoom.h"
#include"Bitmap.h"
#include"ZoomList.h"
#include"MandelBrot.h"
#include "Rgb.h"



using namespace std;

namespace caveofprogramming{
class FractalCreator{
private:
    const int f_width{0},f_height{0};
    unique_ptr<ZoomList> zoomList;
    unique_ptr<Bitmap> bitmap;
    unique_ptr<int[]> iterationNum;
    unique_ptr<int[]> pixelNum;

public:
    FractalCreator(int width, int height);
    ~FractalCreator();
    void run(string fileName);
    void addZoom(const Zoom &zoom);

private:
    void calculateIteration();
    void drawFractal();
   
    void writeBitmap(string fileName);

    
};

}


#endif // FractalCreator_H_
