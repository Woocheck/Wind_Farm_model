#include <armadillo>
#include "gtest/gtest.h"
#include "../src/grid/node.h"

Node node( 1, 0, "node_name", 2.0, 3.0, 33000.0, 0.1, 1);

TEST(Node, get_number)
{
    EXPECT_EQ(1,node.getNumber());
}
TEST(Node, get_paent)
{
    EXPECT_EQ(0,node.getParentNumber());
}
TEST(Node, get_name)
{
    EXPECT_EQ("node_name",node.getName());
}
TEST(Node, get_p)
{
    EXPECT_EQ(2.0,node.getP());
}
TEST(Node, get_q)
{
    EXPECT_EQ(3.0,node.getQ());
}
TEST(Node, get_Module)
{
    EXPECT_EQ(33000.0,node.getVoltageModule());
}
TEST(Node, get_Argumnt)
{
    EXPECT_EQ(0.1,node.getVoltageArgument());
}
TEST(Node, get_Category)
{
    EXPECT_EQ(1,node.getCategory());
}

TEST(Node, set_number)
{
    node.setNumber( 2 );
    EXPECT_EQ(2,node.getNumber());
}
TEST(Node, set_paent)
{
    node.setParentNumber( 1 );
    EXPECT_EQ(1,node.getParentNumber());
}
TEST(Node, set_name)
{
    node.setName( "new_node_name" );
    EXPECT_EQ( "new_node_name", node.getName() );
}
TEST(Node, set_p)
{
    node.setP( 1.0 );
    EXPECT_EQ( 1.0,node.getP() );
}
TEST(Node, set_q)
{
    node.setQ( 2.0 );
    EXPECT_EQ( 2.0,node.getQ() );
}
TEST(Node, set_Module)
{
    node.setVoltageModule( 22000.0 );
    EXPECT_EQ( 22000.0, node.getVoltageModule() );
}
TEST(Node, set_Argumnt)
{
    node.setVoltageArgument( 0.2 );
    EXPECT_EQ( 0.2, node.getVoltageArgument() );
}
TEST(Node, set_Category)
{
    node.setCategory( 5 );
    EXPECT_EQ( 5, node.getCategory() );
}
