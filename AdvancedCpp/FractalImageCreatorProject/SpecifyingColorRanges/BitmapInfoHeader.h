#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

namespace caveofprogramming{
#include<cstdint>
using namespace std;

#pragma pack(push,2)                     //remove padding
struct BitmapInfoHeader{            //bitmap actual data
    int32_t headerSize{40};         //  
    int32_t width;
    int32_t height;
    int16_t planes{1};              //layer feature of bitmap
    int16_t bitsPerPixel{24};          //1byte for each color R,G,B
    int32_t compression{0};
    int32_t dataSize{0};               //init to 0, set later
    int32_t horizonttalResolution{2400};
    int32_t verticalResolution{2400};
    int32_t colors{0};                  //may not be required
    int32_t importantColors{0};         //--"--
};
#pragma pack(pop)
}
#endif