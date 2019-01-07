#include<iostream>
#include"Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main(){
    int const WIDTH = 800;
    int const HEIGHT = 600;
    Bitmap bitmap(WIDTH,HEIGHT);

    double min = 99999;
    double max = -99999;

    //range of 2 => -1 to 1 for fractal
    for(int x=0; x<WIDTH;x++){
        for(int y=0;y<HEIGHT;y++){
            //xFractal = offset * scaling
            double xFractal = (x - WIDTH/2) * 2.0/WIDTH;      //0 to 800 offset to symmetric -400 to 400 * scaled to 2/width
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
            
            if(xFractal<min) min = xFractal;
            if(xFractal>max) max = xFractal;
       }
    }

    cout << min << "," << max << endl;



    //bitmap.setPixel(0,2,255,255,255);
    
    bitmap.write("test.bmp");
    

    return 0;
}
