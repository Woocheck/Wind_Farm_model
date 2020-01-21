#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <memory>
class Node
{
    private:
        int _nodeNumber;
        int _parentNumber;
        std::string _nodeName;
        double _nodeP;
        double _nodeQ;
        double _nodeVoltageModul;
        double _nodeVoltageAngle;
        int _category;
        
        std::vector<Node> _childrens;
    
    public:
        Node(){};
        Node( int number,
              int parent,
              std::string name,
              double p,
              double q,
              double u,
              double arg,              
              int cat,
              std::complex<double> vol):
              _nodeNumber( number ),
              _parentNumber( parent ),
              _nodeName( name ),
              _nodeP( p ),
              _nodeQ( q ),
              _nodeVoltageModul( u ),
              _nodeVoltageAngle( arg ),
              _category( cat ) {};
        
        void setNumber(int number );
        void setParentNumber( int parentNumber );
        void setName( std::string name );
        void setP( double p );
        void setQ( double q );
        void setCategory( int cat );
        void setVoltage( std::complex<double> vol );
        void setVoltage( double re, double im );
        void setVoltageTrigonometric( double mod, double arg );

        int getNumber();
        int getParentNumber();
        std::string getName();
        double getP();
        double getQ();
        double getVoltageModule();
        double getVoltageArgument();
        int getCategory();
        std::complex<double>  getVoltage();
        std::complex<double>  getNodePower();

        
};
#endif 
