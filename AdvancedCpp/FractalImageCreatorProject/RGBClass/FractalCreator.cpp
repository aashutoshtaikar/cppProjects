#include"FractalCreator.h"

using namespace std;

namespace caveofprogramming{
    FractalCreator::FractalCreator(int width, int height):
    f_width(width),f_height(height),
    bitmap(new Bitmap(f_width,f_height)),
    zoomList(new ZoomList(f_width,f_height)),
    iterationNum(new int[MandelBrot::MAX_ITERATIONS]{0}),
    pixelNum(new int[f_width*f_height]{0})
    {
        zoomList->add(Zoom(f_width/2,f_height/2,4.0/f_width));
    }
    
    FractalCreator::~FractalCreator(){
        //delete zoomList;
        //delete bitmap;
        //cout << "Pointers flushed" << endl;
    }

    void FractalCreator::run(string fileName){
        calculateIteration();
        drawFractal();
        writeBitmap(fileName);
    }

    void FractalCreator::calculateIteration(){
        #pragma omp parallel for num_threads(8)
        for(int x=0; x<f_width;x++){
            for(int y=0;y<f_height;y++){

                pair<double,double> zPair=zoomList->doZoom(x,y);
                int iterations = MandelBrot::getIterations(zPair.first,zPair.second);
                if(iterations!=MandelBrot::MAX_ITERATIONS){ // ensures (max)iterations which contain black pixels are not incremented/stored
                    iterationNum[iterations]++;             //store pixelcount for that iterationNum
                }
                pixelNum[y*f_width+x] = iterations;           // store iterationcount for that pixelNum [y*WIDTH+x] considering rgb as one pixel
            } 
               
       }
    }

    void FractalCreator::drawFractal(){
        Rgb startColor(0,0,0);  //black
        Rgb endColor(0,0,255);
        Rgb colorDiff = endColor - startColor;

         //validating the histogram
        int pixelCount = 0;
        for(int i =0;i<=MandelBrot::MAX_ITERATIONS;i++){
          cout << iterationNum[i] << " " << flush;
          pixelCount += iterationNum[i];
        }
        cout << endl << pixelCount << ";" << f_width*f_height <<endl;
        #pragma omp parallel for num_threads(8)
    for(int x=0; x<f_width;x++){
        for(int y=0;y<f_height;y++){
            //cout << "Section 2 Thread:" << omp_get_thread_num() << " executing" << endl;
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = pixelNum[y*f_width+x];   //get iterations this way

            if(iterations!=MandelBrot::MAX_ITERATIONS){
                double hue = 0.0;
                for(int i=0;i<=iterations;i++){
                    hue +=((double)iterationNum[i])/pixelCount;
                }
                red = startColor.red + colorDiff.red*hue;
                green = startColor.green + colorDiff.green*hue;
                blue = startColor.blue + colorDiff.blue*hue;
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
