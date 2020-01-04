#ifndef _GRID_H_
#define _GRID_H_

#include <map>

#include "./node.h"
#include "./graph.h"

class Model
{
    private:
        CableLine _elements;
        Node _root;
    public:
        Model();

        void reloadModel();
        int  calculateCurrentFlow();
        int  calculatePowerFlow();
        int  calculateCurrentPowerFlow();
        int  calculateVoltageLevels();

    private:
        
        
    
};

#endif
