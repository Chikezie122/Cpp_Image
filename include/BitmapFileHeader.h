
#ifndef BITMAPFILEHEADER_H_INCLUDED
#define BITMAPFILEHEADER_H_INCLUDED

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace caveofprogramming{

struct BitmapFileHeader {
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;

};

} /*namespace caveofprogramming */


#endif // BITMAPFILEHEADER_H_INCLUDED
