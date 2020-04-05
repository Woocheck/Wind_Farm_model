#include "./newtonRaphson.h"

void NewtonRaphsonAlgorithm::calculate()
{
  jacobianMatrixCalculation();
  imbalanceCalculation();
  while( !isEpsilonGreater() )
  {
    equationSystemResolve();
    calculateNewStateVector();
    imbalanceCalculation();
  }
}

void NewtonRaphsonAlgorithm::imbalanceCalculation()
{
  valuesUD = getValuesUD();
  imbalanceVal = Jacobian  * valuesUD;
}

void NewtonRaphsonAlgorithm::jacobianMatrixCalculation()
{
   for( int i { 0 }; i < recivingNodes + sourceNodes; i++ )
    for( int j { 0 }; j < recivingNodes + sourceNodes; j++ )
    {
        if( isH( i, j ) )
        {
            Jacobian( i, j ) = H( i, j );
        }
        else if( isN( i, j ) )
        {
            Jacobian( i, j ) = N( i, j );
        }
        else if( isK( i, j ) )
        {
            Jacobian( i, j ) = K( i, j );
        }
        else if( isL( i, j ) )
        {
            Jacobian( i, j ) = L( i, j );
        }
    }
}
void NewtonRaphsonAlgorithm::equationSystemResolve()
{
    arma::solve(valuesUD, Jacobian, imbalanceVal);
}
void NewtonRaphsonAlgorithm::calculateNewStateVector()
{
    valuesUD = valuesUD + imbalanceVal;
}
bool NewtonRaphsonAlgorithm::isEpsilonGreater()
{
    return  *(std::max_element( imbalanceVal.begin(), imbalanceVal.end() )) < epsilon;
}
double NewtonRaphsonAlgorithm::H(int i, int j)
{
    if( i != j)
    {
        auto [Ui, Uj, Di, Dj, Gij, Bij] = getGraphParameters( i, j );
        return Ui * Uj * ( Gij * sin(Di-Dj) - Bij * cos(Di-Dj) ); 
    }
    else if( i = j )
    {
        double result {0};
        for( int a=0; a<j; a++)
        {
            auto [Ui, Uj, Di, Dj, Gij, Bij] = getGraphParameters( i, a );
            result += -1 * Ui * Uj * ( Gij * sin(Di-Dj) - Bij * cos(Di-Dj) );
        }
        return result;
    }
}

double NewtonRaphsonAlgorithm::N(int i, int j)
{
    if( i != j)
    {
        auto [Ui, Uj, Di, Dj, Gij, Bij] = getGraphParameters( i, j );
        return Ui * ( Gij * sin(Di-Dj) + Bij * cos(Di-Dj) ); 
    }
    else if( i = j )
    {
        double result {0};
        {
            auto [Ui, Uj, Di, Dj, Gij, Bij] = getGraphParameters( i, i );
            result += 2 * Ui * Gij;
        }
        for( int a=0; a<j; a++)
        {
            auto [Ui, Uj, Di, Dj, Gij, Bij] = getGraphParameters( i, a );
            result += Ui * Uj *( Gij * sin(Di-Dj) + Bij * cos(Di-Dj) );
        }
        return result;
    }
}
double NewtonRaphsonAlgorithm::K(int i, int j)
{
    if( i != j)
    {
        auto [Ui, Uj, Di, Dj, Gij, Bij] = getGraphParameters( i, j );
        return -1 * Ui * Uj * ( Gij * sin(Di-Dj) + Bij * cos(Di-Dj) ); 
    }
    else if( i = j )
    {
        double result {0};
        for( int a=0; a<j; a++)
        {
            auto [Ui, Uj, Di, Dj, Gij, Bij] = getGraphParameters( i, a );
            result += Ui * Uj * ( Gij * sin(Di-Dj) + Bij * cos(Di-Dj) );
        }
        return result;
    }
}
double NewtonRaphsonAlgorithm::L(int i, int j)
{
    if( i != j)
    {
        auto [Ui, Uj, Di, Dj, Gij, Bij] = getGraphParameters( i, j );
        return Ui * ( Gij * sin(Di-Dj) - Bij * cos(Di-Dj) ); 
    }
    else if( i = j )
    {
        double result {0};
        {
            auto [Ui, Uj, Di, Dj, Gij, Bij] = getGraphParameters( i, i );
            result += -2 * Ui * Gij;
        }
        for( int a=0; a<j; a++)
        {
            auto [Ui, Uj, Di, Dj, Gij, Bij] = getGraphParameters( i, a );
            result += Ui * Uj *( Gij * sin(Di-Dj) - Bij * cos(Di-Dj) );
        }
        return result;
    }
}
bool NewtonRaphsonAlgorithm::isH( int i, int j )
{
    return i < recivingNodes && j < sourceNodes;
}
bool NewtonRaphsonAlgorithm::isN( int i, int j )
{
    return i < recivingNodes && j < recivingNodes + sourceNodes;
}
bool NewtonRaphsonAlgorithm::isK( int i, int j )
{
    return i >= recivingNodes && i < recivingNodes + sourceNodes && j < recivingNodes;
}
bool NewtonRaphsonAlgorithm::isL( int i, int j )
{
    return     i >= recivingNodes && i < recivingNodes + sourceNodes 
            && j >= recivingNodes && j < recivingNodes + sourceNodes;
}
auto NewtonRaphsonAlgorithm::getGraphParameters( int i, int j )
{   
    auto Y = _grid.getAdmitanceMatrix();
    return std::make_tuple( _grid.getNodeU( i ),
                            _grid.getNodeU( j ),
                            _grid.getNodeArgU( i ),
                            _grid.getNodeArgU( j ),
                            Y.at( i, j ).real(),
                            Y.at( i, j ).imag());
}
auto NewtonRaphsonAlgorithm::getValuesUD()
{
    arma::Col<double> result( nodesNuber + sourceNodes );
    
    for( int i{0}; i < recivingNodes; i++ )
    {
        result.at( i ) = _grid.getNodeU[ i ];
    }
    for( int i = recivingNodes; i < nodesNuber; i++)
    {
        result.at( i ) = _grid.getNodeArgU[ i ];
    }
   return result;
}

