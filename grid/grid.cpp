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
        auto rawToFloat = [&](int x){ return std::atof( rawGraph.at( x ).c_str() ) };

        _elements[ std::stoi( rawGraph.at( 0 ) )].setElementNumber( rawToInt(0) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setNodesNumbers( rawToInt(1),rawToInt(2) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setName( rawGraph.at( 3 ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setVoltage( rawToFloat(4) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setCrossection( rawToFloat( 5 ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setResistance( rawToFloat( 6 ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setReactance( rawToFloat( 7 ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setSusceptance( rawToFloat( 8 ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setLenght( rawToFloat( 9 ) );
        _elements[ std::stoi( rawGraph.at( 0 ) )].setNominalId( rawToFloat( 10 ) );   
    }
}
void Model::loadNodes()
{
    InputData nodesFile("./nodes.txt");
    auto nodesString { std::make_shared<InputData>( nodesFile )};

    for( auto rawNode : nodesString->getData() )
    {
        _nodes[ std::stoi( rawNode.at( 0 ) )].setNumber( std::stoi( rawNode.at( 0 ) ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setName(rawNode.at( 1 ));
        _nodes[ std::stoi( rawNode.at( 0 ) )].setParentNumber( std::stoi( rawNode.at( 2 ) ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setP( std::atof( rawNode.at( 3 ).c_str() ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setQ( std::atof( rawNode.at( 4 ).c_str() ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setVoltageModule( std::atof( rawNode.at( 5 ).c_str() ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setVoltageArgument( std::atof( rawNode.at( 6 ).c_str() ) );
        _nodes[ std::stoi( rawNode.at( 0 ) )].setCategory( std::stoi( rawNode.at( 7 ) ) );
    }
}
void Model::calculateAdmitanceMatrix()
{
    auto matrixSize { _nodes.size() };
    std::cout << "matrixSize" <<  matrixSize << "\n";
    std::cout << "elementsSize" <<  _elements.size() << "\n";
    _admitanceMatrix.resize( matrixSize, matrixSize );
    for(auto element : _elements )
    {
        auto [i,j] = element.second.getNodesNumbers();
        std::complex<double> Z = std::real( element.second.getResistance() ) + std::imag( element.second.getReactance() );
        std::complex<double> Z0 = std::imag( element.second.getSusceptance()/2 );
        
        if( i!= j)
        {
            std::cout << i << ", " << j << "->";
            std::cout << i << ", " << std::real(1) / Z << "\n";
            _admitanceMatrix.at( i, j ) = std::real(1) / Z;
        }
        else 
        {
            std::cout << i << ", " << j << "->";
            std::cout << i << ", " << ( std::real(1)/Z ) + ( std::imag(1)/Z0 ) << "\n";
            _admitanceMatrix.at( i, i ) += ( std::real(1)/Z ) + ( std::imag(1)/Z0 );
            _admitanceMatrix.at( j, j ) += ( std::real(1)/Z ) + ( std::imag(1)/Z0 );
        }
         
    }
    
}


