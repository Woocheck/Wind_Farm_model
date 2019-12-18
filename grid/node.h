#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <string>

class Node
{
    private:
        int _nodeNumber;
        std::string _nodeName;
        float _nodeP;
        float _nodeQ;
        int _category;
    
    public:
        Node( int number,
              std::string name,
              float p,
              float q,
              int cat):
              _nodeNumber ( number ),
              _nodeName ( name ),
              _nodeP ( p ),
              _nodeQ ( q ),
              _category ( cat ) {};
        
        void setNumber(int name );
        void setName( std::string name );
        void setP( float p );
        void setQ( float q );
        void setCategory( int cat );

        int getNumber();
        std::string getName();
        float getP();
        float getQ();
        int getCategory();

};


#endif 