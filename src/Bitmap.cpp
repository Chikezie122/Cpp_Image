#include <iostream>
#include <cstdint>
#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace std;
using namespace caveofprogramming;

namespace caveofprogramming{

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{})
{

}

bool Bitmap::write(string filename)
{
    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (m_width*m_height*3);
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    ofstream inputFile;

    inputFile.open(filename, ios::out | ios::binary);
    if(!inputFile){
        return false;
    }
    inputFile.write((char *)&fileHeader, sizeof(fileHeader));
    inputFile.write((char *)&infoHeader, sizeof(infoHeader));
    inputFile.write((char *)m_pPixels.get(), m_width * m_height * 3);

    inputFile.close();
    return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
    uint8_t *pPixels = m_pPixels.get(); // this gets a pointer to the memory block representing the whole screen

    pPixels += (y * 3) * m_width + (x * 3); // gets the current location of the pixels being pointed to

    pPixels[0] = blue;
    pPixels[1] = green;
    pPixels[2] = red;
}

Bitmap::~Bitmap()
{
    //dtor
}

} /* namespace caveofprogramming */
