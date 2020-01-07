#ifndef _GRID_H_
#define _GRID_H_

#include <map>

#include "./node.h"
#include "./graph.h"

class Model
{
    private:
        std::map<int, CableLine> _elements;
        std::map<int, Node> _nodes;
        Node _root;

    public:

        void reloadModel();
        int  calculateCurrentFlow();
        int  calculatePowerFlow();
        int  calculateCurrentPowerFlow();
        int  calculateVoltageLevels();

    private:
        
        
    
};

#endif
