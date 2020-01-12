#include "./grid.h"

std::complex<double> Model::strToComplex( std::string value )
{
    std::istringstream is('(' + value + ')');
    std::complex<double> conwertedValue;
    is >> conwertedValue;

    return conwertedValue;
}

void Model::reloadModel()
{
    InputData nodesfile("./nodes.txt");

    auto nodesString { std::make_shared<InputData>( nodesfile )};

    for( auto rawNode : nodesString->getData() )
    {
        _nodes[ std::stoi( rawNode.at( 0 ) )].setNumber( std::stoi( rawNode.at( 0 ) ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setName(rawNode.at( 1 ));
        _nodes[ std::stoi( rawNode.at( 0 ) )].setParent( std::stoi( rawNode.at( 2 ) ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setP( std::atof( rawNode.at( 3 ).c_str() ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setQ( std::atof( rawNode.at( 4 ).c_str() ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setVoltage( 
                                                strToComplex( rawNode.at( 5 ).c_str() ));
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

