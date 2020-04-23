#include <armadillo>
#include "gtest/gtest.h"
#include "../src/grid/node.h"

Node node( 1, 0, "node_name", 2.0, 3.0, 33000.0, 0.1, 1);

TEST(Node_class, get_number)
{
    EXPECT_EQ(1,node.getNumber());
}
TEST(Node_class, get_paent)
{
    EXPECT_EQ(0,node.getParentNumber());
}
TEST(Node_class, get_name)
{
    EXPECT_EQ("node_name",node.getName());
}
TEST(Node_class, get_p)
{
    EXPECT_EQ(2.0,node.getP());
}
TEST(Node_class, get_q)
{
    EXPECT_EQ(3.0,node.getQ());
}
TEST(Node_class, get_Module)
{
    EXPECT_EQ(33000.0,node.getVoltageModule());
}
TEST(Node_class, get_Argumnt)
{
    EXPECT_EQ(0.1,node.getVoltageArgument());
}
TEST(Node_class, get_Category)
{
    EXPECT_EQ(1,node.getCategory());
}

TEST(Node_class, set_number)
{
    node.setNumber( 2 );
    EXPECT_EQ(2,node.getNumber());
}
TEST(Node_class, set_paent)
{
    node.setParentNumber( 1 );
    EXPECT_EQ(1,node.getParentNumber());
}
TEST(Node_class, set_name)
{
    node.setName( "new_node_name" );
    EXPECT_EQ( "new_node_name", node.getName() );
}
TEST(Node_class, set_p)
{
    node.setP( 1.0 );
    EXPECT_EQ( 1.0,node.getP() );
}
TEST(Node_class, set_q)
{
    node.setQ( 2.0 );
    EXPECT_EQ( 2.0,node.getQ() );
}
TEST(Node_class, set_Module)
{
    node.setVoltageModule( 22000.0 );
    EXPECT_EQ( 22000.0, node.getVoltageModule() );
}
TEST(Node_class, set_Argumnt)
{
    node.setVoltageArgument( 0.2 );
    EXPECT_EQ( 0.2, node.getVoltageArgument() );
}
TEST(Node_class, set_Category)
{
    node.setCategory( 5 );
    EXPECT_EQ( 5, node.getCategory() );
}
TEST(Node_class, get_voltage)
{
    std::complex<double>  result;
    result = std::polar( 22000.0, 0.2 );

    EXPECT_EQ( result, node.getVoltage() );
}
