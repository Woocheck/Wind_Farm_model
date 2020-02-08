#ifndef _GRID_H_
#define _GRID_H_

#include <map>
#include <string>
#include <complex>
#include <sstream>
#include <armadillo>

#include "./node.h"
#include "./graph.h"
#include "../file/file_model.h"


class Model
{
    private:
        std::map<int, CableLine> _elements;
        std::map<int, Node> _nodes;
        arma::Mat<std::complex<double>> _admitanceMatrix;

    public:
        Model(){};
        void reloadModel();
        arma::Mat<std::complex<double>> getAdmitanceMatrix();
        int getNumberReciving();
        int getNumberSource();
        double getNodeU( int i );
        double getNodeArgU( int i );


    private:
        std::complex<double> strToComplex( std::string value ); 
        void calculateAdmitanceMatrix();   
        void loadGraphs();
        void loadNodes();
        
    
};

#endif
