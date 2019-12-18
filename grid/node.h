#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <string>
#include <complex>

class Node
{
    private:
        int _nodeNumber;
        std::string _nodeName;
        float _nodeP;
        float _nodeQ;
        int _category;
        std::complex<float> _nodeVoltage;
    
    public:
        Node( int number,
              std::string name,
              float p,
              float q,
              int cat,
              std::complex<float> vol):
              _nodeNumber ( number ),
              _nodeName ( name ),
              _nodeP ( p ),
              _nodeQ ( q ),
              _category ( cat ),
              _nodeVoltage ( vol ) {};
        
        void setNumber(int name );
        void setName( std::string name );
        void setP( float p );
        void setQ( float q );
        void setCategory( int cat );
        void setVoltage( std::complex<float> vol );
        void setVoltage( float re, float im );

        int getNumber();
        std::string getName();
        float getP();
        float getQ();
        int getCategory();
        std::complex<float>  getVoltage();

};


#endif 