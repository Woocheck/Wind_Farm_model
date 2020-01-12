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
    {
    InputData nodesFile("./nodes.txt");
    auto nodesString { std::make_shared<InputData>( nodesFile )};

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
    {
    InputData graphFile( "./graphs.txt");
    auto graphString { std::make_shared<InputData>( graphFile ) };

    for( auto rawGraph : graphString->getData() )
    {
        _elements[ std::stoi( rawGraph.at( 0 ) )];
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

