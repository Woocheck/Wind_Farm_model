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

    for(int i = 0; i<4; i++)
    {
        _nodes[i].printChildrens();
    }
    for(int i = 0; i<4; i++ )
    {
        std::cout << "node: " << i << "\n";
        for( int y = 0; y<4; y++)
        {
            if( _nodes[y].getNumber() != _nodes[i].getNumber()
                && _nodes[i].getNumber() == _nodes[y].getParentNumber() )
            {
                std::cout << "children: " << y << "\n";
                _nodes[i].addChildren( y );
            }
        }
    }
    for(int i = 0; i<4; i++)
    {
        _nodes[i].printChildrens();
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

