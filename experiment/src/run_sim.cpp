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

using namespace bwi_gridworld;

int main(int argc, char *argv[]){
    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    al_init_primitives_addon();
    al_init_image_addon();

    display = al_create_display(1000, 1000);
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    std::srand(time(0)); //seeds random number generator with the current time

    Grid grid(new RandomAgent(), display);
    grid.runExperiments();



    al_destroy_display(display);

    return 0;
}
