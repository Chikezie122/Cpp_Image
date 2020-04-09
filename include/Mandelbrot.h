#ifndef MANDELBROT_H
#define MANDELBROT_H

namespace caveofprogramming{

    class Mandelbrot
    {
        public:
            static const int MAX_ITERATIONS = 1000;

        public:
            Mandelbrot();
            ~Mandelbrot();

            static int getIterations(double x, double y);
    };

}

#endif // MANDELBROT_H
