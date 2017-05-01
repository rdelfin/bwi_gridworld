#include <vector>
#include <time.h>
#include "Agent.h"
#include <cstddef>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

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

        ALLEGRO_DISPLAY* display;

        ALLEGRO_BITMAP *robot_img, *star_img;

        void reset();
        void event_found();
        bool alreadyOccupied(int, int);
        void checkIfEventFound(int);
        int printResults();



    public:
        Grid(Agent *prototype, ALLEGRO_DISPLAY* display);
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

        void draw_board();

        ~Grid();
    };

}

