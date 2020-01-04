#include "./node.h"


void Node::printChildrens()
{
    for(auto x : _childrens)
    {
        std::cout << x;
    }
    std::cout << "\n";
}
int Node::addChildren( int child )
{
    _childrens.push_back( child );
}
std::vector<int> Node::getChildrensList()
{
    return _childrens;
}

std::complex<double> Node::getCurrent()
{
    std::complex<double> current {};

    if( sizeof( _childrens ) )
    {
        return current;
    }
    else
    {
        return ( std::real( _nodeP) + std::imag( _nodeQ ) ) / _nodeVoltage;
    }
    
}
std::complex<double> Node::getPowerFromChildrens()
{
    std::complex<double> power {};
    for( auto element : _childrens )
    {
        ;
    }

    return power;
}

std::complex<double>  Node::getNodePower()
{
    std::complex<double> power {};

    if( sizeof( _childrens ) )
    {
        // power += getCurrentFromChildrens();
        power += ( std::real( _nodeP) + std::imag( _nodeQ ) ) / _nodeVoltage;
        return power;
    }
    else
    {
        return ( std::real( _nodeP) + std::imag( _nodeQ ) ) / _nodeVoltage;
    }
}

void Node::setNumber( int name )
{
    _nodeNumber = name;
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
