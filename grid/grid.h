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
        Model()
        {

        };
        void reloadModel();

    private:
        std::complex<double> strToComplex( std::string value ); 
        void calculateAdmitanceMatrix();   
        
    
};

#endif
