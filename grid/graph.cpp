#include "./graph.h"
#include <iostream>

std::complex<double> CableLine::getZ()
{
    std::complex<double> z( _resistance * _lenght, 
                           _reactance * _lenght );

    return z; 
}

std::complex<double> CableLine::getY()
{
    std::complex<double> y( _conductance * _lenght, 
                           _susceptance * _lenght );
    y/=2;

    return y; 
}

std::complex<double> CableLine::getU1( std::complex<double> I2, std::complex<double> U2 )
{
    std::complex<double> Z = getZ();
    std::complex<double> Y = getY();
    std::complex<double> a = std::real( 1 ) + Z * Y;
    std::complex<double> b = Z;

    return a * U2 + b * I2;   
}

std::complex<double> CableLine::getI1( std::complex<double> I2, std::complex<double> U2 )
{
    std::complex<double> Z = getZ();
    std::complex<double> Y = getY();
    std::complex<double> c = std::real( 2 ) * Y + Z * Y * Y;
    std::complex<double> d = std::real( 1 ) + Z * Y;

    return c * U2 + d * I2; 
}