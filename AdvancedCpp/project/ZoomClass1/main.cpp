#include<iostream>
#include<cstdint>
#include<memory>
#include<math.h>
#include"Bitmap.h"
#include"MandelBrot.h"
#include<omp.h>
#include"ZoomList.h"
using namespace std;
using namespace caveofprogramming;

int main(){
    static const int WIDTH = 800;
    static const int HEIGHT = 600;
 double time0 = omp_get_wtime();
    Bitmap bitmap(WIDTH,HEIGHT);

    ZoomList zoomList(WIDTH,HEIGHT);

    zoomList.add(Zoom(WIDTH/2,HEIGHT/2,4.0/WIDTH));
    zoomList.add(Zoom(295,HEIGHT-202,0.1)); //init the scale in to >0
    zoomList.add(Zoom(312,HEIGHT-304,0.1)); //init the scale in to >0

    //zoomList.add(Zoom(295,HEIGHT-202,0.1)); //init the scale in to >0

    unique_ptr<int[]> iterationNum(new int[MandelBrot::MAX_ITERATIONS]{0});
    unique_ptr<int[]> pixelNum(new int[WIDTH*HEIGHT]{0});

   //store iterations
//#pragma omp parallel for num_threads(4)
    omp_set_num_threads(8);
    #pragma omp parallel for
    for(int x=0; x<WIDTH;x++){
        for(int y=0;y<HEIGHT;y++){
             //cout << "Section 1 Thread:" << omp_get_thread_num() << " executing" << endl;
            // double xFractal = (x - WIDTH/2 -200) * 2.0/WIDTH;      //0 to 800 (offset) to symmetric -1 to 1 * (scaled) to 2/width
            // double yFractal = (y - HEIGHT/2 ) * 2.0/HEIGHT;
            // int iterations = MandelBrot::getIterations(xFractal,yFractal);

            pair<double,double> zPair=zoomList.doZoom(x,y);
            int iterations = MandelBrot::getIterations(zPair.first,zPair.second);
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

            ////setting hue by checking the current iteration
#pragma omp parallel for
    for(int x=0; x<WIDTH;x++){
        for(int y=0;y<HEIGHT;y++){
            //cout << "Section 2 Thread:" << omp_get_thread_num() << " executing" << endl;
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = pixelNum[y*WIDTH+x];   //get iterations this way

            if(iterations!=MandelBrot::MAX_ITERATIONS){
                double hue = 0.0;
                for(int i=0;i<=iterations;i++){
                    hue +=((double)iterationNum[i])/pixelCount;
                }
                green = pow(255,hue); //255^hue , hue= -1 to 1
            }
            bitmap.setPixel(x,y,red,green,blue);
        }
    }

    bitmap.write("test.bmp");
        double time1 = omp_get_wtime();

    std::cout<<"Finished: " << time1-time0 << " seconds" <<endl;
    return 0;
}




