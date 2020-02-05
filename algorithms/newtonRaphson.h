#ifndef _NEWTON_RAPHSON_H_
#define _NEWTON_RAPHSON_H_

#include <map>
#include <string>
#include <complex>
#include <sstream>
#include <armadillo>

#include "../grid/grid.h"

class NewtonRaphsonAlgorithm
{
    private:
        Model _grid;
        arma::Mat<std::complex<double>> Jacobian;

        
    public:
        NewtonRaphsonAlgorithm( Model& grid ): _grid( grid){};
        void calculate();
        
    private:
        void imbalanceCalculation();
        void jacobianMatrixCalculation();
        void equationSystemResolve();
        void calculateNewStateVector();
        bool isEpsilonGreater();

};

#endif