
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



using namespace std;

namespace caveofprogramming{
class FractalCreator{
private:
    const int f_width{0},f_height{0};
    ZoomList *zoomList = nullptr;
    Bitmap *bitmap = nullptr;
    int *iterationNum =nullptr;
    int *pixelNum =nullptr;
public:
    FractalCreator(int width, int height);
    ~FractalCreator();

    void calculateIteration(int width,int height);
    void drawFractal(int width,int height);
    void addZoom(const Zoom &zoom);
    void writeBitmap(string fileName);

};

}


#endif // FractalCreator_H_
