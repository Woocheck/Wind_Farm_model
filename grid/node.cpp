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
    _nodeVoltage = std::real( re ) + std::imag( im );
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
int Node::getCategory()
{
    return _category;
}

std::complex<double>  Node::getVoltage()
{
    return _nodeVoltage;
}

int Node::getParentNumber()
{
    return _parentNumber;
}
