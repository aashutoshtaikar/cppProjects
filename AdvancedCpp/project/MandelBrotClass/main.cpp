#include<iostream>
#include<cstdint>
#include<memory>
#include"Bitmap.h"
#include"MandelBrot.h"
#include<omp.h>
using namespace std;
using namespace caveofprogramming;

int main(){
    static const int WIDTH = 800;
    static const int HEIGHT = 600;
    double min = 99999;
    double max = -99999;
    Bitmap bitmap(WIDTH,HEIGHT);
 
    unique_ptr<int[]> iterationNum(new int[MandelBrot::MAX_ITERATIONS]{0});  
    unique_ptr<int[]> pixelNum(new int[WIDTH*HEIGHT]{0});
    
    omp_set_num_threads(4);
    #pragma omp parallel for
    for(int x=0; x<WIDTH;x++){
        for(int y=0;y<HEIGHT;y++){
            //xFractal = offset * scaling
            double xFractal = (x - WIDTH/2 -200) * 2.0/HEIGHT;      //0 to 800 (offset) to symmetric -1 to 1 * (scaled) to 2/width
            double yFractal = (y - HEIGHT/2 ) * 2.0/HEIGHT;
            
            int iterations = MandelBrot::getIterations(xFractal,yFractal);            
            if(iterations!=MandelBrot::MAX_ITERATIONS){ // ensures (max)iterations which contain black pixels are not incremented/stored
                iterationNum[iterations]++;             //store pixelcount for that iterationNum
            }

            pixelNum[y*WIDTH+x] = iterations;           // store iterationcount for that pixelNum [y*WIDTH+x] considering rgb as one pixel
            
            //map that to a color
            uint8_t color = (uint8_t)(256*(double)iterations/MandelBrot::MAX_ITERATIONS);
            color = color*color*color;
            bitmap.setPixel(x,y,0,color,0);

            if(color<min) min = color;
            if(color>max) max = color;     
       }
    }

    //validating the histogram
    int pixelCount = 0;
    for(int i =0;i<=MandelBrot::MAX_ITERATIONS;i++){
        cout << iterationNum[i] << " " << flush;
        pixelCount += iterationNum[i];
    }
    cout << endl << pixelCount << ";" << WIDTH*HEIGHT <<endl;

    bitmap.write("test.bmp");
    return 0;
}
