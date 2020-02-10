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
        arma::Mat<double> Jacobian;
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
        double H(int i, int j);
        double N(int i, int j);
        double K(int i, int j);
        double L(int i, int j);
        bool isH( int i, int j );
        bool isN( int i, int j );
        bool isK( int i, int j );
        bool isL( int i, int j );
};

#endif
