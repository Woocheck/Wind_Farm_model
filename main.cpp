#include <iostream>
#include <math.h>
#include <complex>

#include "./grid/graph.h"

int main(int argc, char const *argv[])
{
    CableLine line( 100, "BU - UW DU", 33000, 1000, 0.04080, 0.170, 0.255, 2*M_1_PI*50*0.255, 100, 0, 5000 );

    std::complex<float> lineZ;
    std::complex<float> lineY;

    lineZ = line.getZ();

    std::cout << lineZ << std::endl;


    return 0;
}
