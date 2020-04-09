#ifndef BITMAPINFOHEADER_H_INCLUDED
#define BITMAPINFOHEADER_H_INCLUDED

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace caveofprogramming{

struct BitmapInfoHeader {
    int32_t headerSize{40}; // Size of the struct file that is being used
    int32_t width;
    int32_t height;
    int16_t planes{1};
    int16_t bitsPerPixel{24}; // Using the RGB colours, each colour is 8-bits
    int32_t compression{0};
    int32_t dataSize{0};
    int32_t horizontalResolution{2400};
    int32_t verticalResolution{2400};
    int32_t colors{0};
    int32_t importantColors{0};

};

} /*namespace caveofprogramming */


#endif // BITMAPINFOHEADER_H_INCLUDED

