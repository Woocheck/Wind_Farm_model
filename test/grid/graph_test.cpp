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
TEST( Graph_class, get_Nodes_Numbers )
{
    auto nodeNumbes = std::make_pair<int,int>(0,1);
    EXPECT_EQ( nodeNumbes , line.getNodesNumbers() );
}
TEST( Graph_class, get_Conductance )
{
    auto conductance = 1 / (std::real( 5 ) + std::imag( 0.5 ));
    EXPECT_EQ( conductance, line.getConductance() );
}
TEST( Graph_class, get_I1 )
{
    
    
}/*
TEST( Graph_class, get_U1 )
{
    EXPECT_EQ( 1000, line.getCrossection() );
}
TEST( Graph_class, get_I2 )
{
    EXPECT_EQ( 1000, line.getCrossection() );
}
TEST( Graph_class, get_U2)
{
    EXPECT_EQ( 1000, line.getCrossection() );
}
*/