#include "./grid.h"

void Model::reloadModel()
{
    Node element( 0, 0, "0", 0, 0, 0, 330000 );
    _nodes.insert({0,element});
    Node element1( 1, 0, "1", 3400000, 0, 1, 330000 );
    _nodes.insert({1,element1});
    Node element2( 2, 1, "2", 3400000, 0, 1, 330000 );
    _nodes.insert({2,element2});
    Node element3( 3, 1, "3", 3400000, 0, 1, 330000 );
    _nodes.insert({3,element3});

    for(auto node : _nodes )
    {
        node.second.printChildrens();
    }
    for(auto node : _nodes )
    {
        std::cout << "node: " << node.first << "\n";
        for( auto x : _nodes)
        {
            if( x.second.getNumber() != node.second.getNumber()
                && node.second.getNumber() == x.second.getParentNumber() )
            {
                std::cout << "children: " << node.first << "\n";
                node.second.addChildren( x.first );
            }
        }
    }
    for(auto node : _nodes )
    {
        node.second.printChildrens();
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

