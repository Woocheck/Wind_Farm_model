#include <armadillo>
#include "gtest/gtest.h"
#include "../src/grid/grid.h"

#include "../src/algorithms/newtonRaphson.h"

class AlgorithmTest: public ::testing::Tsest
{
    private:
    Model grid;
    NewtonRaphsonAlgorithm  newtonRaphsonAlgorithm;

    public:
    AlgorithmTest( Model g)
    {
        grid = g;
        newtonRaphsonAlgorithm.NewtonRaphsonAlgorithmS( grid );
    };
    
};
TEST( NwetonRaphson_class, calculate )
{
    
    grid.reloadModel();
    newtonRaphsonAlgorithm.calculate();
}