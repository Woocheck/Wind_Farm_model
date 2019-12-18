#include "./node.h"

void Node::setNumber( int name )
{
    _nodeNumber = name;
};

void Node::setName( std::string name )
{
    _nodeName = name;
};

void Node::setP( float p )
{
    _nodeP = p;
};
void Node::setQ( float q )
{
    _nodeQ = q;
};
void Node::setCategory( int cat )
{
    _category = cat;
};

void Node::setVoltage( std::complex<float> vol )
{
    _nodeVoltage = vol;
};

void Node::setVoltage( float re, float im )
{
    _nodeVoltage.real = re;
    _nodeVoltage.imag = im;
};

int Node::getNumber()
{
    return _nodeNumber;
};
std::string Node::getName()
{
    return _nodeName;
};
float Node::getP()
{
    return _nodeP;
};
float Node::getQ()
{
    return _nodeQ;
};
int Node::getCategory()
{
    return _category;
};

std::complex<float>  Node::setVoltage()
{
    return _nodeVoltage;
};