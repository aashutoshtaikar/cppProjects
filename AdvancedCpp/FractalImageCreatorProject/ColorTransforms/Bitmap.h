#ifndef BITMAP_H_
#define BITMAP_H_
#include<string>
#include<cstdint>
#include<memory>
using namespace std;

namespace caveofprogramming{

class Bitmap{   //class to define, set and write bitmap data 
private:
    int m_width{0};
    int m_height{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr};    //equivalent to unsigned char

public:
    //Bitmap();
    Bitmap(int width, int height);  //create a bitmap
    int setPixel(int x,int y,uint8_t red,uint8_t green, uint8_t blue);
    bool write(string fileName);    //write to file
    //virtual ~Bitmap();
};

}

#endif