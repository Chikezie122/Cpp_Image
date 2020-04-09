#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace caveofprogramming{
    Mandelbrot::Mandelbrot()
    {
        //ctor
    }

    Mandelbrot::~Mandelbrot()
    {
        //dtor
    }

    int Mandelbrot::getIterations(double x, double y){
        complex<double> z = 0;
        complex<double> c(x,y);

        int iterations = 0;

        while(iterations < MAX_ITERATIONS){ // Since we can't iterate to infinity, we have to set it to the maximum number of iterations

            z = z*z + c; // Mandlebrot's equation

            if(abs(z) > 2){
                break;
            }

            iterations++; // Number of iterations that is required for the algorithm to reach convergence on the graph
        }

        return iterations;
    }

}
