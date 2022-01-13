#include <allegro5/allegro.h>

int main(int argc, char** argv) {
    al_init();
    
    al_create_display(640, 480);
    
    al_clear_to_color(al_map_rgb(255, 0, 255));
    
    al_flip_display();
    
    while (!0) {
        al_draw_pixel(640, 480, al_map_rgb(255, 0, 255));
        al_rest(5.0f);
    }

    return 0;
}
