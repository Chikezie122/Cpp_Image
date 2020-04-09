#ifndef BITMAP_H
#define BITMAP_H

#include <iostream>
#include <cstdint>
#include <memory>

using namespace std;

namespace caveofprogramming{

class Bitmap
{
private:
    int m_width{0};
    int m_height{0};
    unique_ptr<uint8_t[]> m_pPixels{nullptr}; // pointer to an array that contains the size of the full pixel image
public:
    Bitmap(int width, int height); // size of the bitmap  to be created
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue); // size of each colour to be used and position of each pixel in the bitmap
    bool write(string filename); // Used to write into the bitmap file
    virtual ~Bitmap();
};

}
#endif // BITMAP_H
