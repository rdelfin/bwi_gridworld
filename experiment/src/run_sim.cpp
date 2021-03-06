#include "grid/grid.h"
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
/*
* Driver file for the simulated GRID project.
* Here is where all agents will be assembled into a vector and passed into the created grid object.
*
*/

#include <agent/RandomAgent.h>
#include <grid/gui.h>
#include <thread>

using namespace bwi_gridworld;

void simulation(Grid* grid);
void gui_thread(Grid* grid);

int main(int argc, char *argv[]) {
    bool gui = !(argc > 1 && std::string(argv[1]) == std::string("--no-gui"));

    std::srand(time(0)); //seeds random number generator with the current time

    Grid grid(new RandomAgent(), gui);

    std::thread simThread(simulation, &grid);

    if(gui) {
        std::thread guiThread(gui_thread, &grid);
        guiThread.join();
    }

    simThread.join();

    return 0;
}

void simulation(Grid* grid) {
    grid->runExperiments();
}

void gui_thread(Grid* grid) {
    Gui gui(grid);
    while(grid->running) {
        gui.update();
    }
}
