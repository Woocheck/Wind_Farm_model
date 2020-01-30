#include "./grid.h"
#include <armadillo>

std::complex<double> Model::strToComplex( std::string value )
{
    std::istringstream is('(' + value + ')');
    std::complex<double> conwertedValue;
    is >> conwertedValue;

    return conwertedValue;
}

void Model::reloadModel()
{
    loadGraphs();
    loadNodes();
    calculateAdmitanceMatrix();
    std::cout << _admitanceMatrix << std::endl;
}

void Model::loadGraphs()
{
    InputData graphFile( "./graphs.txt");
    auto graphString { std::make_shared<InputData>( graphFile ) };
    
    for( auto rawGraph : graphString->getData() )
    {
        auto rawToInt = [&](int x){ return std::stoi( rawGraph.at( x ) ); };
        auto rawToFloat = [&](int x){ return std::atof( rawGraph.at( x ).c_str() ); };
        auto position = [&](int x){ return std::stoi( rawGraph.at( x ) ); };

        _elements[ position( 0 ) ].setElementNumber( rawToInt(0) );
        _elements[ position( 0 ) ].setNodesNumbers( rawToInt(1),rawToInt(2) );
        _elements[ position( 0 ) ].setName( rawGraph.at( 3 ) );
        _elements[ position( 0 ) ].setVoltage( rawToFloat(4) );
        _elements[ position( 0 ) ].setCrossection( rawToFloat( 5 ) );
        _elements[ position( 0 ) ].setResistance( rawToFloat( 6 ) );
        _elements[ position( 0 ) ].setReactance( rawToFloat( 7 ) );
        _elements[ position( 0 ) ].setSusceptance( rawToFloat( 8 ) );
        _elements[ position( 0 ) ].setLenght( rawToFloat( 9 ) );
        _elements[ position( 0 ) ].setNominalId( rawToFloat( 10 ) );   
    }
}
void Model::loadNodes()
{
    InputData nodesFile("./nodes.txt");
    auto nodesString { std::make_shared<InputData>( nodesFile )};

    for( auto rawNode : nodesString->getData() )
    {
        auto rawToInt = [&](int x){ return std::stoi( rawNode.at( x ) ); };
        auto rawToFloat = [&](int x){ return std::atof( rawNode.at( x ).c_str() ); };
        auto position = [&](int x){ return std::stoi( rawNode.at( x ) ); };

        _nodes[ position( 0 ) ].setNumber( rawToInt(0) );
        _nodes[ position( 0 ) ].setName(rawNode.at( 1 ) );
        _nodes[ position( 0 ) ].setParentNumber( rawToInt( 2 ) );
        _nodes[ position( 0 ) ].setP( rawToFloat( 3 ) );
        _nodes[ position( 0 ) ].setQ( rawToFloat( 4 ) );
        _nodes[ position( 0 ) ].setVoltageModule( rawToFloat( 5 ) );
        _nodes[ position( 0 ) ].setVoltageArgument( rawToFloat( 6 ) );
        _nodes[ position( 0 ) ].setCategory( rawToInt( 7 ) );
    }
}
void Model::calculateAdmitanceMatrix()
{
    auto matrixSize { _nodes.size() };
    _admitanceMatrix.resize( matrixSize, matrixSize );

    for(auto element : _elements )
    {
        auto [i,j] = element.second.getNodesNumbers();
        std::complex<double> Z = std::real( element.second.getResistance() ) + std::imag( element.second.getReactance() );
        std::complex<double> Z0 = std::real( 0 ) + std::imag( 1/( element.second.getSusceptance()/2 ) );

        if( i!= j)
        {
            _admitanceMatrix.at( i, j ) = std::real(1) / Z;
            _admitanceMatrix.at( j, i ) = std::real(1) / Z;
        };
        std::cout << "Element = " << element.second.getSusceptance()/2 << "   1/Element= " << 1/( element.second.getSusceptance()/2) << "    Z0= " << Z0 <<"\n";
        _admitanceMatrix.at( i, i ) = _admitanceMatrix.at( i, i ) + Z0;
        _admitanceMatrix.at( j, j ) = _admitanceMatrix.at( j, j ) + Z0;   
        for(int x{0}; x < matrixSize; x++)
        {
            if(x!=i)
                _admitanceMatrix.at( i, i ) += _admitanceMatrix.at( i, x );
        } 
    }
}


