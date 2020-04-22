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

std::complex<double> CableLine::getU1( std::complex<double> I2, 
                                       std::complex<double> U2 )
{
    std::complex<double> Z = getZ();
    std::complex<double> Y = getY();
    std::complex<double> a = std::real( 1 ) + Z * Y;
    std::complex<double> b = Z;

    return a * U2 + b * I2;   
}

std::complex<double> CableLine::getI1( std::complex<double> I2, 
                                       std::complex<double> U2 )
{
    std::complex<double> Z = getZ();
    std::complex<double> Y = getY();
    std::complex<double> c = std::real( 2 ) * Y + Z * Y * Y;
    std::complex<double> d = std::real( 1 ) + Z * Y;

    return c * U2 + d * I2; 
}

std::complex<double> CableLine::getI2( std::complex<double> I1, 
                                       std::complex<double> U1 )
{
    std::complex<double> Z = getZ();
    std::complex<double> Y = getY();

    std::complex<double> a = std::real( 1 ) + Z * Y;
    std::complex<double> b = Z;
    std::complex<double> c = std::real( 2 ) * Y + Z * Y * Y;
    std::complex<double> d = std::real( 1 ) + Z * Y;

    std::complex<double> det_A = std::real( 1 ) / ( (a*d) - (c*d) );

    return det_A * std::real( -1 ) * c * U1 + det_A * a * I1; 
}

std::complex<double> CableLine::getU2( std::complex<double> I1, 
                                       std::complex<double> U1 )
{
    std::complex<double> Z = getZ();
    std::complex<double> Y = getY();

    std::complex<double> a = std::real( 1 ) + Z * Y;
    std::complex<double> b = Z;
    std::complex<double> c = std::real( 2 ) * Y + Z * Y * Y;
    std::complex<double> d = std::real( 1 ) + Z * Y;

    std::complex<double> det_A = std::real( 1 ) / ( (a*d) - (c*d) );

    return det_A * d * U1 + det_A * std::real( -1 ) * b * I1; 
}

void CableLine::setElementNumber( int number )
{
    Graph::_graphNumber = number;
}
void CableLine::setNodesNumbers( int begin, int end )
{
    Graph::_beginningNode = begin;
    Graph::_endNode = end;
}
void CableLine::setName( std::string name )
{
    _name = name;
}
void CableLine::setVoltage( double voltage )
{
    _nominalVoltage = voltage;
}
void CableLine::setCrossection( double crossection )
{
    _crossection = crossection;
}
void CableLine::setResistance( double resistance )
{
    _resistance = resistance;
}
void CableLine::setReactance( double reactance )
{
    _reactance = reactance;
}
void CableLine::setSusceptance( double capacity )
{
    _susceptance = 2*M_1_PI*50*capacity; 
}
void CableLine::setLenght( double lenght )
{
    _lenght = lenght;
}
void CableLine::setNominalId( double id )
{
    _nominalId = id;
}

int CableLine::getNumber()
{
    return Graph::_graphNumber;
}
std::pair<int,int> CableLine::getNodesNumbers()
{
    return std::make_pair( Graph::_beginningNode, Graph::_endNode );
}
std::string CableLine::getName()
{
    return _name;
}
double CableLine::getVoltage()
{
    return _nominalVoltage;
}
double CableLine::getCrossection( double crossection )
{
    return _crossection;
}
double CableLine::getResistance()
{
    return _resistance;
}
double CableLine::getReactance()
{
    return _reactance;
}
double CableLine::getSusceptance()
{
    return _susceptance;
}
double CableLine::getLenght()
{
    return _lenght;
}
double CableLine::getNominalId()
{
    return _nominalId;
}
std::complex<double> CableLine::getConductance()
{
    return 1 / (std::real( _resistance ) + std::imag( _reactance ) );
}