#include <iostream>
#include <math.h>
#include <complex>


#include "./grid/grid.h"
#include "./algorithms/newtonRaphson.h"

int main(int argc, char const *argv[])
{
//{
    InputData data("graphs.txt");
    
    auto dataPointer { std::make_shared<InputData>( data )};
 /*   
    for (auto x : dataPointer->getHeader() )
    {
        std::cout << x << ' ' << std::endl;
    }
    
    for (auto x : dataPointer->getData()) 
    {
        for (auto y : x) 
        {
            std::cout << y << ' ';
        }
        std::cout << std::endl;
    };
}
{
    InputData data("nodes.txt");
    
    auto dataPointer { std::make_shared<InputData>( data )};
    
    for (auto x : dataPointer->getHeader() ){
        std::cout << x << ' ' << std::endl;
    }
    
    for (auto x : dataPointer->getData()) {
        for (auto y : x) {
            std::cout << y << ' ';
        }
        std::cout << std::endl;
    };
}*/
    Model grid;

    grid.reloadModel();

    NewtonRaphsonAlgorithm  nrAlgorithm( grid );
    
    nrAlgorithm.calculate();
    
    return 0;
}
