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
        int nodesNuber;
        int recivingNodes;
        int sourceNodes;
        int balanceNodes { 1 };
        double epsilon { 0 };
        
    public:
        NewtonRaphsonAlgorithm( Model& grid ): _grid( grid)
        {
            recivingNodes = _grid.getNumberReciving();
            sourceNodes = _grid.getNumberSource();
            nodesNuber = recivingNodes + sourceNodes;
            Jacobian.set_size( nodesNuber + sourceNodes, nodesNuber + sourceNodes);
        };
        void calculate();
        
    private:
        void imbalanceCalculation();
        void jacobianMatrixCalculation();
        void equationSystemResolve();
        void calculateNewStateVector();
        bool isEpsilonGreater();

};

#endif