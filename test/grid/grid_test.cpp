#include <armadillo>
#include "gtest/gtest.h"
#include "../src/grid/grid.h"

#include "../src/algorithms/newtonRaphson.h"

InputData data("graphs.txt");
auto dataPointer { std::make_shared<InputData>( data )};
Model grid;

TEST( Grid_class, get_number_Reciving )
{
    grid.reloadModel();
    EXPECT_EQ( 1, grid.getNumberReciving() );
}