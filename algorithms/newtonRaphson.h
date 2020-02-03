#ifndef _NEWTON_RAPHSON_H_
#define _NEWTON_RAPHSON_H_

#include <complex>
#include "../grid/grid.h"

class NewtonRaphsonAlgorithm
{
    private:
        Model _grid;
        
    public:
        NewtonRaphsonAlgorithm()
        {
            _grid.reloadModel();
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