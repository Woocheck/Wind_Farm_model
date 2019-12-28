#include "./graph.h"
#include <iostream>

std::complex<float> CableLine::getCurrent()
{
    getZ();
}

std::complex<float> CableLine::getZ()
{
    std::complex<float> z( _resistance * _lenght, 
                           _reactance * _lenght );

    return z; 
}

std::complex<float> CableLine::getY()
{
    std::complex<float> y( _conductance * _lenght, 
                           _susceptance * _lenght );
    
    y/=2;

    return y; 
}