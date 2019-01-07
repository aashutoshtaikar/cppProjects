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

   //store itrations 
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
       }
    }

    //validating the histogram
    int pixelCount = 0;
    for(int i =0;i<=MandelBrot::MAX_ITERATIONS;i++){
        cout << iterationNum[i] << " " << flush;
        pixelCount += iterationNum[i];
    }
    cout << endl << pixelCount << ";" << WIDTH*HEIGHT <<endl;

    //setting hue by checking the current iteration
    #pragma omp parallel for
    for(int x=0; x<WIDTH;x++){
        for(int y=0;y<HEIGHT;y++){
            int iterations = pixelNum[y*WIDTH+x];   //get iterations this way
            
            double hue = 0.0;
            //adds up all pixels contained in iterationNum till iterations
            for(int i=0;i<=iterations;i++){
                hue +=((double)iterationNum[i])/pixelCount;
            }
            uint8_t red = 0;
            uint8_t green = hue*255;
            uint8_t blue = 0;

            bitmap.setPixel(x,y,red,green,blue);
        }
    }

    bitmap.write("test.bmp");
    return 0;
}
