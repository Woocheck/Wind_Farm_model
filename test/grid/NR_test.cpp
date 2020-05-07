#include <armadillo>
#include "gtest/gtest.h"
#include "../src/grid/grid.h"

#include "../src/algorithms/newtonRaphson.h"

Model grid;


NewtonRaphsonAlgorithm  newtonRaphsonAlgorithm( grid );
TEST( NwetonRaphson_class, calculate )
{
    grid.reloadModel();
    newtonRaphsonAlgorithm.calculate();
}