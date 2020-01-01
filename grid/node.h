#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <string>
#include <complex>
#include <vector>

class Node
{
    private:
        int _nodeNumber;
        std::string _nodeName;
        int _parentNumber;
        double _nodeP;
        double _nodeQ;
        int _category;
        std::complex<double> _nodeVoltage;
        std::vector<Node> _childrens;
    
    public:
        Node( int number,
              int parent,
              std::string name,
              double p,
              double q,
              int cat,
              std::complex<double> vol):
              _nodeNumber( number ),
              _parentNumber( parent ),
              _nodeName( name ),
              _nodeP( p ),
              _nodeQ( q ),
              _category( cat ),
              _nodeVoltage( vol ) {};
        
        void setNumber(int number );
        void setParent( int parentNumber );
        void setName( std::string name );
        void setP( double p );
        void setQ( double q );
        void setCategory( int cat );
        void setVoltage( std::complex<double> vol );
        void setVoltage( double re, double im );

        int getNumber();
        int getParentNumber();
        std::string getName();
        double getP();
        double getQ();
        int getCategory();
        std::complex<double>  getVoltage();
        std::complex<double>  getNodePower();

        int addChildren( Node children );
        std::complex<double> getCurrentFromChildrens();
        std::complex<double> getCurrent();
        std::complex<double> getPowerFromChildrens();
};
#endif 
