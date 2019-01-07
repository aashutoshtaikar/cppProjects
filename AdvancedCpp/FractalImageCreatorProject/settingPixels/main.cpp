#include<iostream>
#include"Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main(){
    int const WIDTH = 256;
    int const HEIGHT = 256;
    Bitmap bitmap(WIDTH,HEIGHT);

    // for(int i=0; i<WIDTH;i++){
    //     //for(int j=0;j<HEIGHT;j++){
    //         bitmap.setPixel(i,0,255,0,0);
    //         bitmap.setPixel(i,255,255,0,0);
    //    // }
    // }


    //     for(int j=0;j<HEIGHT;j++){
    //         bitmap.setPixel(0,j,255,0,0);
    //         bitmap.setPixel(255,j,255,0,0);
    //     }

    // for(int x=0; x<WIDTH;x++){
    //     for(int y=0;y<HEIGHT;y++){
    //         if((((WIDTH/2)*3)*WIDTH +((HEIGHT/2)*3)) - 2*3.14*((y*3)*WIDTH +(x*3))==100){
    //               bitmap.setPixel(x,y,255,0,0);
    //         }
          
    //     }
    // }



    //bitmap.setPixel(0,2,255,255,255);
    
    bitmap.write("test.bmp");
    

    return 0;
}
