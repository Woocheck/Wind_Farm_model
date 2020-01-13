#ifndef _GRID_H_
#define _GRID_H_

#include <map>
#include <string>
#include <complex>
#include <sstream>

#include "./node.h"
#include "./graph.h"
#include "../file/file_model.h"

class Model
{
    private:
        std::map<int, CableLine> _elements;
        std::map<int, Node> _nodes;
        // Node _root;

    public:
        Model()
        {

        };
        void reloadModel();
        int  calculateCurrentFlow();
        int  calculatePowerFlow();
        int  calculateCurrentPowerFlow();
        int  calculateVoltageLevels();

    private:
        std::complex<double> strToComplex( std::string value );    
        
    
};

#endif
