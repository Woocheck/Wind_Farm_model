#include "./grid.h"

void Model::reloadModel()
{
    Node element1( 1, 0, "1", 3400000, 0, 1, 330000 );
    _nodes.insert({1,element1});
    Node element2( 2, 1, "2", 3400000, 0, 1, 330000 );
    _nodes.insert({2,element2});
    Node element3( 3, 1, "3", 3400000, 0, 1, 330000 );
    _nodes.insert({3,element3});

    _root.setNumber( 0 );
    _root.setParent( 0 );
    _root.setName( "0");
    _root.setP( 0 );
    _root.setQ( 0 );
    _root.setVoltage( 33000 );
    _root.setCategory( 0 );
    auto parent = _root;
    while( _nodes.size() )
    {
        for(auto node : _nodes )
        {
            if()
        }
    }
   
}
int Model::calculateCurrentFlow()
{

}

int Model::calculatePowerFlow()
{

}

int Model::calculateCurrentPowerFlow()
{

}

int Model::calculateVoltageLevels()
{

}

