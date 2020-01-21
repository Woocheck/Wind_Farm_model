#include "./node.h"



void Node::setNumber( int name )
{
    _nodeNumber = name;
}

void Node::setParentNumber( int number )
{
    _parentNumber = number;
}

void Node::setName( std::string name )
{
    _nodeName = name;
}

void Node::setP( double p )
{
    _nodeP = p;
}
void Node::setQ( double q )
{
    _nodeQ = q;
}
void Node::setVoltageModule( double module )
{
    _nodeVoltageModul = module;
}
void Node::setVoltageArgument( double argument )
{
    _nodeVoltageAngle = argument;
}
void Node::setCategory( int cat )
{
    _category = cat;
}

void Node::setVoltage( std::complex<double> vol )
{
    _nodeVoltage = vol;
}

void Node::setVoltage( double re, double im )
{
    _nodeVoltageModul = std::abs( ( re ) + std::imag( im ) );
    _nodeVoltageAngle = std::arg( ( re ) + std::imag( im ) );
}
void Node::setVoltageTrigonometric( double mod, double arg )
{
    _nodeVoltageModul = mod;
    _nodeVoltageModul = arg;
}

int Node::getNumber()
{
    return _nodeNumber;
}
std::string Node::getName()
{
    return _nodeName;
}
double Node::getP()
{
    return _nodeP;
}
double Node::getQ()
{
    return _nodeQ;
}
double Node::getVoltageModule()
{
    return _nodeVoltageModul;
}
double Node::getVoltageArgument()
{
    return _nodeVoltageAngle;
}
int Node::getCategory()
{
    return _category;
}
std::complex<double>  Node::getVoltage()
{
    return std::polar( _nodeVoltageModul, _nodeVoltageAngle);
}

int Node::getParentNumber()
{
    return _parentNumber;
}
