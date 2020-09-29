#include <armadillo>
#include "gtest/gtest.h"
#include "../src/grid/grid.h"

#include "../src/algorithms/newtonRaphson.h"

class AlgorithmTest: public ::testing::Test
{
    public:
    Model grid;
    NewtonRaphsonAlgorithm  newtonRaphsonAlgorithm;

    public:
    AlgorithmTest( Model g): 
        newtonRaphsonAlgorithm{ NewtonRaphsonAlgorithm(g) }{};
    
};

TEST( NwetonRaphson_class, calculate )
{
    
}