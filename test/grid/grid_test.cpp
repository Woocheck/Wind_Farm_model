#include <armadillo>
#include "gtest/gtest.h"
#include "../src/grid/grid.h"

#include "../src/algorithms/newtonRaphson.h"



TEST( Grid_class, get_number_Reciving )
{
    Model grid;
    grid.reloadModel();
    EXPECT_EQ( 2, grid.getNumberReciving() );
}

TEST( Grid_class, get_number_Sources )
{
    Model grid;
    grid.reloadModel();
    EXPECT_EQ( 2, grid.getNumberSource() );
}
TEST( Grid_class, print_Nodes )
{
    Model grid;
    grid.reloadModel();
    grid.printNodes();
}