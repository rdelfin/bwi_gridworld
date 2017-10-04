//
// Created by rdelfin on 4/30/17.
//

#ifndef GRIDWORLD_GUI_H
#define GRIDWORLD_GUI_H

#include "grid.h"

#include <allegro5/allegro_font.h>

namespace bwi_gridworld {
    class Gui {
    public:
        Gui(Grid* g);

        void update();

        ~Gui();

    private:
        void logic();
        void draw();

        Grid* g;

        ALLEGRO_DISPLAY* display;
        ALLEGRO_BITMAP *robot_img, *star_img;
        ALLEGRO_BITMAP *bar_img, *divider_img;
        ALLEGRO_FONT* main_font;

        int xOffset, yOffset, sqrW, sqrH;
    };
}


#endif //GRIDWORLD_GUI_H
