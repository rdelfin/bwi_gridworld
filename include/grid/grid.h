#include <vector>
#include <time.h>
#include "Agent.h"
#include <cstddef>
#include <mutex>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#ifndef __BWI_GRIDWORLD_GRID__
#define __BWI_GRIDWORLD_GRID__

namespace bwi_gridworld {

    struct Pos{
        int x,y;
        int time;
        Pos(int x, int y, int time);
        Pos();

        bool operator==(const Pos& pos);
    };

    class Grid{
    private:
        int eventsCreated;
        int eventsFound;
        int step_count;

        std::vector<Pos> event_locations;
        std::vector<Pos> agent_positions;
        std::vector<bwi_gridworld::Agent*> agents;

        void reset();
        void event_found();
        bool alreadyOccupied(int, int);
        void checkIfEventFound(int);
        int printResults();

        std::mutex event_mutex;
        std::mutex agent_mutex;

    public:
        Grid(Agent *prototype);
        const static int width = 10;
        const static int height = 10;
        bool running;
        bool validMove(int, char);
        int eventInit();
        const int getWidth();
        const int getHeight();
        void runExperiments();
        void next();
        int step(int, char);
        const int* getPos(int);

        const std::vector<Pos>& getEventLocations();
        const std::vector<Pos>& getAgentLocations();

        std::mutex& getEventMutex();
        std::mutex& getAgentMutex();

        ~Grid();
    };

}

#endif

