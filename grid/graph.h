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
        std::complex<double> getCurrent(); 

 };

 class CableLine : public Graph
 {
     private:
        int _elementNumber { 0 };
        std::string _name {};
        double _nominalVoltage { 0 };
        double _crossection { 0 };
        double _resistance { 0 };
        double _reactance { 0 };
        double _conductance { 0 };
        double _susceptance { 0 };
        double _lenght { 0 };
        double _nominalId { 0 };
        double _shortcutCurrent1s { 0 };
    
    public:
        CableLine(){};
        CableLine( int num,
                   std::string name,
                   double vol,
                   double cross,
                   double res,
                   double react,
                   double capacity,
                   double lenght,
                   double id,
                   double cur1s ):
                   _elementNumber( num ),
                   _name( name ),
                   _nominalVoltage( vol ),
                   _crossection( cross ),
                   _resistance( res ),
                   _reactance( react ),
                   _susceptance( 2*M_1_PI*50*capacity ),
                   _lenght( lenght ),
                   _nominalId( id ),
                   _shortcutCurrent1s( cur1s ) {};

        std::complex<double> getI1( std::complex<double> I2, std::complex<double> U2 );
        std::complex<double> getU1( std::complex<double> I2, std::complex<double> U2 );
        std::complex<double> getI2( std::complex<double> I1, std::complex<double> U1 );
        std::complex<double> getU2( std::complex<double> I1, std::complex<double> U1 );
    
    private:
    
        std::complex<double> getZ();
        std::complex<double> getY();

                   
 };


#endif