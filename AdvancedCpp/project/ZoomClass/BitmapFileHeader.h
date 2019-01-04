#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

namespace caveofprogramming{
#include <cstdint>
using namespace std;

//creating a bitmap 
//we want public members to access directly
#pragma pack(push,2)                  //aligns the struct to multiple of 2 byte boundaries
struct BitmapFileHeader{
    //two bytes containing letters
    char header[2]{'B','M'};    //file type specifier
    int32_t fileSize;           //size
    int32_t reserved{0};        //not used
    int32_t dataOffset;         //how long into the file the actual data begins
};
#pragma pack(pop)
}

#endif

