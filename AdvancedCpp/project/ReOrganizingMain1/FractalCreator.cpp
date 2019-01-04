#include"FractalCreator.h"

using namespace std;

namespace caveofprogramming{
    FractalCreator::FractalCreator(int width, int height):
    f_width(width),f_height(height),
    bitmap(new Bitmap(f_width,f_height)),
    zoomList(new ZoomList(f_width,f_height)),
    iterationNum(new int[MandelBrot::MAX_ITERATIONS]{0}),
    pixelNum(new int[f_width*f_height]{0}){}
    
    FractalCreator::~FractalCreator(){
        //delete zoomList;
        //delete bitmap;
        //cout << "Pointers flushed" << endl;
    }

    void FractalCreator::calculateIteration(int width,int height){
        #pragma omp parallel for num_threads(8)
        for(int x=0; x<width;x++){
            for(int y=0;y<height;y++){

                pair<double,double> zPair=zoomList->doZoom(x,y);
                int iterations = MandelBrot::getIterations(zPair.first,zPair.second);
                if(iterations!=MandelBrot::MAX_ITERATIONS){ // ensures (max)iterations which contain black pixels are not incremented/stored
                    iterationNum[iterations]++;             //store pixelcount for that iterationNum
                }
                pixelNum[y*width+x] = iterations;           // store iterationcount for that pixelNum [y*WIDTH+x] considering rgb as one pixel
            } 
            //cout << ".";      
       }
    }

    void FractalCreator::drawFractal(int width,int height){
         //validating the histogram
        int pixelCount = 0;
        for(int i =0;i<=MandelBrot::MAX_ITERATIONS;i++){
          cout << iterationNum[i] << " " << flush;
          pixelCount += iterationNum[i];
        }
        cout << endl << pixelCount << ";" << width*height <<endl;
        #pragma omp parallel for num_threads(8)
    for(int x=0; x<width;x++){
        for(int y=0;y<height;y++){
            //cout << "Section 2 Thread:" << omp_get_thread_num() << " executing" << endl;
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = pixelNum[y*width+x];   //get iterations this way

            if(iterations!=MandelBrot::MAX_ITERATIONS){
                double hue = 0.0;
                for(int i=0;i<=iterations;i++){
                    hue +=((double)iterationNum[i])/pixelCount;
                }
                red = pow(255,hue); //255^hue , hue= -1 to 1
            }
            bitmap->setPixel(x,y,red,green,blue);
        }
        
    }

    }

    void FractalCreator::addZoom(const Zoom &zoom){
        zoomList->add(zoom);
    }

    void FractalCreator::writeBitmap(string fileName){
        bitmap->write(fileName+".bmp");
    }    
}
