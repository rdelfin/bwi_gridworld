//
// Created by rdelfin on 4/30/17.
//

#ifndef GRIDWORLD_GUI_H
#define GRIDWORLD_GUI_H

#include "grid.h"

namespace bwi_gridworld {
    class Gui {
    public:
        Gui(Grid* g);

        void update();

        ~Gui();

    private:
        Grid* g;

        ALLEGRO_DISPLAY* display;
        ALLEGRO_BITMAP *robot_img, *star_img;

        int xOffset, yOffset, sqrW, sqrH;
    };
}


#endif //GRIDWORLD_GUI_H
