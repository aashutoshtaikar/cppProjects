
#if !defined(FractalCreator_H_)
#define FractalCreator_H_
#include <iostream>
#include<string>
#include<memory>
#include<math.h>
#include<vector>
#include<omp.h>

#include"Zoom.h"
#include"Bitmap.h"
#include"ZoomList.h"
#include"MandelBrot.h"
#include "Rgb.h"
#include<assert.h>


using namespace std;

namespace caveofprogramming{
class FractalCreator{
private:
    int f_width,f_height;
    unique_ptr<ZoomList> zoomList;
    unique_ptr<Bitmap> bitmap;
    unique_ptr<int[]> iterationNum;
    unique_ptr<int[]> pixelNum;
    
    int pixelCount{0};
    vector<int> f_ranges;
    vector<Rgb> f_colors;
    vector<int> f_rangeTotals;
    bool f_bGotFirstRange{false};

public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    void run(string fileName);
    void addZoom(const Zoom &zoom);
    void addRange(double rangeEnd,const Rgb& rgb);    //no of iterations of the end point to the range

private:
    void calculateIteration();
    void getPixelsfromIterationNum();
    void calculateRangeTotals();
    void drawFractal();
    void writeBitmap(string fileName);
     int getRange(int iterations) const;
    

    
};

}


#endif // FractalCreator_H_
