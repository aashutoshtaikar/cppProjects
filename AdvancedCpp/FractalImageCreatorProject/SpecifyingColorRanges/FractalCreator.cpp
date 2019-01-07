#include"FractalCreator.h"

using namespace std;

namespace caveofprogramming{

FractalCreator::FractalCreator(int width, int height):
    f_width(width),f_height(height),
    bitmap(new Bitmap(f_width,f_height)),
    zoomList(new ZoomList(f_width,f_height)),
    iterationNum(new int[MandelBrot::MAX_ITERATIONS]{0}),
    pixelNum(new int[f_width*f_height]{0}){
        zoomList->add(Zoom(f_width/2, f_height/2, 4.0/f_width));
    }
    
FractalCreator::~FractalCreator(){}

void FractalCreator::run(string fileName){
    calculateIteration();
    getPixelsfromIterationNum();
    calculateRangeTotals();
    drawFractal();
    writeBitmap(fileName);
}

void FractalCreator::addRange(double rangeEnd,const Rgb &rgb){
    f_ranges.push_back(rangeEnd * MandelBrot::MAX_ITERATIONS);
    f_colors.push_back(rgb);

    //ensures that while adding the first range we don't add zero
    if(f_bGotFirstRange){
        f_rangeTotals.push_back(0);
    }

    f_bGotFirstRange = true;
}

void FractalCreator::calculateRangeTotals(){
    //get range of iterations 
    int rangeIndex = 0;

    for(int i=0;i<MandelBrot::MAX_ITERATIONS;i++){
        int pixels = iterationNum[i];               //get pixels for that iterationNum
        
        if(i >= f_ranges[rangeIndex+1]){
            rangeIndex++;
        }

        f_rangeTotals[rangeIndex] += pixels; 
    }

    int overallTotal = 0;
    for(int value : f_rangeTotals){
        cout << "Range total: " << value << endl;
        overallTotal += value;
    }
    //cout << "Debug Overall Total1: " << overallTotal << endl;

}

void FractalCreator::calculateIteration(){
   // #pragma omp parallel for num_threads(8)
    for(int y=0;y<f_height;y++){
        for(int x=0; x<f_width;x++){
            pair<double,double> zPair=zoomList->doZoom(x,y);

            int iterations = MandelBrot::getIterations(zPair.first,zPair.second);
            
            pixelNum[y*f_width+x] = iterations;           // store iterationcount for that pixelNum [y*WIDTH+x] considering rgb as one pixel

            if(iterations!=MandelBrot::MAX_ITERATIONS){ // ensures (max)iterations which contain black pixels are not incremented/stored
                iterationNum[iterations]++;             //store pixelcount for that iterationNum
            }

        }    
   }
}


void FractalCreator::getPixelsfromIterationNum(){
    for(int i =0; i < MandelBrot::MAX_ITERATIONS; i++){
        //cout << iterationNum[i] << " " << flush;  ////displays pixelCount corresponding to each iterationNum
        pixelCount += iterationNum[i];
    }
    //validating the histogram obtained pixel count with actual pixel count
    //cout << endl << pixelCount << ";" << f_width*f_height <<endl;
    //cout << "Debug Overall Total2: " << pixelCount << endl;
}



void FractalCreator::drawFractal(){
    Rgb startColor(0,0,0);  //black
    Rgb endColor(0,0,255);
    Rgb colorDiff = endColor - startColor;
        
    //#pragma omp parallel for num_threads(8)
    for(int y=0; y < f_height; y++){
        for(int x=0; x < f_width; x++){
                
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = pixelNum[y*f_width+x];   //get iterations this way

            if(iterations != MandelBrot::MAX_ITERATIONS){
                
                double hue = 0.0;
                
                for(int i=0; i<= iterations; i++){
                    hue += ((double)iterationNum[i]) / pixelCount;
                }
                
                red = startColor.red + colorDiff.red * hue;
                green = startColor.green + colorDiff.green * hue;
                blue = startColor.blue + colorDiff.blue * hue;
            }

            bitmap->setPixel(x, y, red, green, blue);
        }
    }

}

int FractalCreator::getRange(int iterations) const{
    int range = 0;

    for(int i = 1; i < f_ranges.size();i++){ //skip the 0th element
        range = i;

        if(f_ranges[i]>iterations){
            break;
        }
    }

    range--;

    assert(range > -1);
    assert(range < f_ranges.size());

    return range;
}

void FractalCreator::addZoom(const Zoom &zoom){
    zoomList->add(zoom);
}


void FractalCreator::writeBitmap(string fileName){
    bitmap->write(fileName+"test.bmp");
}    



}
