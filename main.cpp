#include <iostream>
#include <math.h>
#include <complex>

#include "./grid/grid.h"


int main(int argc, char const *argv[])
{
    CableLine line( 100, 0, 1, "BU - UW DU", 33000, 1000, 0.04080, 0.17 * 0.001, 0.255 * 0.000001, 13, 0, 5000 );

    std::complex<double> U2; U2.real( 33000 ); U2.imag( 0 );
    std::complex<double> I2; I2.real( 10 ); I2.imag( 0 );

    std::cout << "I 2: " << I2 << "\n";
    std::cout << "U 2: " << U2 << "\n";

    std::cout << "I 1: " << line.getI1( I2, U2 ) << "\n";
    std::cout << "U 1: " << line.getU1( I2, U2 ) << "\n";

    std::cout << "I 2: " << line.getI2( line.getI1( I2, U2 ), line.getU1( I2, U2 ) ) << "\n";
    std::cout << "U 2: " << line.getU2( line.getI1( I2, U2 ), line.getU1( I2, U2 ) ) << "\n";

    Model model;

    model.reloadModel();
    return 0;
}
