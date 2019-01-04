#include <iostream>
#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace caveofprogramming;
using namespace std;

namespace caveofprogramming{
//Bitmap::Bitmap():m_width(0),m_height(0){}
//new uint8_t[width*height*3]{} <-- curly braces as a modern way to init memory to 0 instead of using memset
Bitmap::Bitmap(int width,int height):m_width(width),m_height(height),m_pPixels(new uint8_t[width*height*3]{}){}

bool Bitmap::write(string fileName){
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*3;
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);//distance from the beginnning to where the data actually starts 
    
    infoHeader.width = m_width;
    infoHeader.height = m_height;

    ofstream file;
    file.open(fileName,ios::out|ios::binary);
    
    if(!file){
        return false;
    }
    
    file.write((char*)&fileHeader,sizeof(fileHeader));
    file.write((char*)&infoHeader,sizeof(infoHeader));
    file.write((char*)m_pPixels.get(),m_width*m_height*3);

    //cannot cast unique_ptr to char*, get() can be used to return a normal pointer which can be casted to char*
    file.close();

    return true;
}

int Bitmap::setPixel(int x,int y,uint8_t red,uint8_t green, uint8_t blue){
    //gets the pointer to whole mem block that represents the whole bitmap
    uint8_t *pPixel = m_pPixels.get();  

    //get a pointer and point at this pixel by x and y
    //cout << (y*3)*m_width +(x*3) <<endl;
    pPixel += (y * 3) * m_width + (x * 3); 

    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;

    return (y*3)*m_width +(x*3);
}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}
//no desturctor as we are using smart pointers


}