// We will be building a fractal image and uploading it to a Bitmap
// A Fractal image is made by combining different algorithms together
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace caveofprogramming;

int main(){
    int const WIDTH = 800;
    int const HEIGHT = 600;

    double min = 999999;
    double max = -999999;
    // In order to change the colors on the fractal, we would use a color histogram to store the number of
    // pixels that have color codes

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 }); // the size of the new array would be the number of maximum
    // iterations
    // The histogram would hold a set of colors to be used in the fractal image

    unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{ 0 }); // array to hold every pixel in the bitmap diagram

    Bitmap bitmap(WIDTH, HEIGHT);

    for(int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            double xFractal = (x - WIDTH/2  - 200) * 2.0/HEIGHT; // Determines the size on the x-axis
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT; // Determines the size on the y-axis

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
             // getting the number of iterations it took the curve to get to its convergence

            fractal[y * WIDTH + x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS){
                histogram[iterations]++;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++){
        total += histogram[i];
    }

     for(int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){

            int iterations = fractal[y * WIDTH + x];

//
//            int iterations = fractal[ y * WIDTH + x];
//
//            if (iterations != Mandelbrot::MAX_ITERATIONS)
//            {
            double hue = 0.0;

            for (int i = 0; i <= iterations; i++){
                hue += ((double)histogram[i])/ total;
            }

            uint8_t red = 0;
            uint8_t green = hue * 255;
            uint8_t blue = 0;
//
//                green = pow(255.0, hue);
//            }

            bitmap.setPixel(x, y,red,green,blue); // This function determines the particular position to draw the fractal
                // and also the color to be used. X and Y are the coordinates for the positions while color is the color be used

        }
     }


    bitmap.write("test.bmp");
    cout << "Finished. " << endl;

    return 0;
}
