#include <armadillo>
#include "gtest/gtest.h"
#include "../src/grid/graph.h"

CableLine line( 100, 
                  0, 
                  1, 
                  "line", 
                  33000.0, 
                  1000, 
                  5, 
                  0.5, 
                  0.5, 
                  200, 
                  5.5, 
                  1000 );

TEST( Graph_class, get_nominal_Voltage )
{
    EXPECT_EQ( 33000.0, line.getVoltage() );
}
TEST( Graph_class, get_crossection )
{
    EXPECT_EQ( 1000, line.getCrossection() );
}