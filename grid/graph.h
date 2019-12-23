#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string>
#include <complex>

 class Graph
 {
    private:

        int _graphNumber {0};
        int _beginningNode {0};
        int _endNode {0};
    public:
        Graph(){};
        std::complex<float> getCurrent(); 

 };

 class CableLine : public Graph
 {
     private:
        int _elementNumber { 0 };
        std::string _name {};
        float _nominalVoltage { 0 };
        float _crossection { 0 };
        float _resistance { 0 };
        float _reactance { 0 };
        float _conductance { 0 };
        float _susceptance { 0 };
        float _lenght { 0 };
        float _nominalId { 0 };
        float _shortcutCurrent1s { 0 };
    
    public:
        CableLine(){};
        CableLine( int num,
                   std::string name,
                   float vol,
                   float cross,
                   float res,
                   float react,
                   float conduct,
                   float suscept,
                   float lenght,
                   float id,
                   float cur1s ):
                   _elementNumber( num ),
                   _name( name ),
                   _nominalVoltage( vol ),
                   _crossection( cross ),
                   _resistance( res ),
                   _reactance( react ),
                   _nominalId( id ),
                   _shortcutCurrent1s( cur1s ) {};

        std::complex<float> getCurrent();
    private:
        std::complex<float> getZ();
        std::complex<float> getY();

                   
 };

#endif