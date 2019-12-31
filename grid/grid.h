#ifndef _GRID_H_
#define _GRID_H_

#include "./node.h"

class Model
{
    private:
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
