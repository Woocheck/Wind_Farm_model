#include <armadillo>
#include "gtest/gtest.h"
#include "../src/grid/grid.h"

#include "../src/algorithms/newtonRaphson.h"

TEST( NwetonRaphson_class, calculate )
{
    Model grid;
    grid.reloadModel();

    NewtonRaphsonAlgorithm  newtonRaphsonAlgorithm( grid );
    newtonRaphsonAlgorithm.calculate();
}