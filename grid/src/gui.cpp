//
// Created by rdelfin on 4/30/17.
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <iostream>

#include "grid/gui.h"
#include "grid/grid.h"

namespace bwi_gridworld {
    Gui::Gui(Grid* g) : g(g), xOffset(250), yOffset(250), sqrW(50), sqrH(50) {
        ALLEGRO_DISPLAY *display = NULL;

        if(!al_init()) {
            std::cerr << "failed to initialize allegro!" << std::endl;
            exit(-1);
        }

        al_init_primitives_addon();
        al_init_image_addon();
        al_init_font_addon();
        al_init_ttf_addon();

        display = al_create_display(1000, 1000);
        if(!display) {
            std::cerr << "failed to create display!" << std::endl;
            exit(-1);
        }

        robot_img = al_load_bitmap("assets/r2d2-128.png");
        star_img = al_load_bitmap("assets/star-128.png");
        bar_img = al_load_bitmap("assets/bar.png");
        divider_img = al_load_bitmap("assets/divider.png");
        main_font = al_load_ttf_font("assets/forced_square.ttf", 20, 0);
    }

    void Gui::update() {
        logic();
        draw();
    }

    void Gui::logic() {
        ALLEGRO_MOUSE_STATE state;
        al_get_mouse_state(&state);

        if(state.buttons & 1) {

        }
    }

    void Gui::draw() {
        // Calcu

        al_clear_to_color(al_map_rgb(100,149,237));

        for(int x = 0; x < g->getWidth(); x++) {
            for(int y = 0; y < g->getHeight(); y++) {
                al_draw_filled_rectangle(x*sqrW + xOffset, y*sqrW + yOffset, (x+1)*sqrW + xOffset, (y+1)*sqrH + yOffset, al_map_rgb(255, 255, 255));
                al_draw_rectangle(x*sqrW + xOffset, y*sqrH + yOffset, (x+1)*sqrW + xOffset, (y+1)*sqrH + yOffset, al_map_rgb(0, 0, 0), 2);
            }
        }

        g->getEventMutex().lock();
        const std::vector<Pos>& event_locations = g->getEventLocations();
        for(auto it = event_locations.begin(); it != event_locations.end(); ++it) {
            al_draw_bitmap(star_img, it->x*sqrW + xOffset, it->y*sqrH + yOffset, NULL);
        }
        g->getEventMutex().unlock();


        g->getAgentMutex().lock();
        const std::vector<Pos>& agent_positions = g->getAgentLocations();
        for(auto it = agent_positions.begin(); it != agent_positions.end(); ++it) {
            al_draw_bitmap(robot_img, it->x*sqrW + xOffset + 5, it->y*sqrH + yOffset + 5, NULL);
        }
        g->getAgentMutex().unlock();

        al_draw_textf(main_font, al_map_rgb(255, 255, 255), 500, 800, 0, "Step #%d", g->getStepCount());
        al_draw_textf(main_font, al_map_rgb(255, 255, 255), 500, 850, 0, "%d events captured", g->getEventsFound());

        al_draw_bitmap(bar_img, 250, 100, 0);
        al_draw_bitmap(divider_img, 237, 100, 0);

        al_flip_display();
        al_rest(0.025);
    }

    Gui::~Gui() {
        al_destroy_bitmap(robot_img);
        al_destroy_bitmap(star_img);
        al_destroy_bitmap(bar_img);
        al_destroy_bitmap(divider_img);
        al_destroy_font(main_font);
        al_destroy_display(display);
    }
}