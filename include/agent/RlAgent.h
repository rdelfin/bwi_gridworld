//
// Created by rdelfin on 4/30/17.
//

#ifndef GRIDWORLD_RLAGENT_H
#define GRIDWORLD_RLAGENT_H

#include <grid/Agent.h>

class RlAgent : public bwi_gridworld::Agent {
    char nextAction(const bwi_gridworld::Pos &currentPos);
    void eventFound(const bwi_gridworld::Pos &currentPos);
    bwi_gridworld::Agent *clone(int id);
};


#endif //GRIDWORLD_RLAGENT_H
