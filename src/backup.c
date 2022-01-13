//#include <allegro5/allegro.h>
//#include <allegro5/allegro_image.h>
//#include <allegro5/allegro_primitives.h>

// Command to run
// gcc -o app app.c -lallegro -lallegro_image -lallegro_dialog -lallegro_main
// ./app

//ALLEGRO_BITMAP *buffer;
//ALLEGRO_BITMAP *itens;
//ALLEGRO_BITMAP *fundo;

//int width = 1048;
//int height = 670;
//int done = 0;

//int main(void) {
////    al_init();
////
////    al_create_display(width, height);
////
////    al_clear_to_color(al_map_rgb(255, 0, 255));
////
////    al_flip_display();
////
////    buffer = al_create_bitmap(width, height);
////    fundo = al_load_bitmap("../img/fundo.bmp");
//
//    // Variables
//    int width = 640;
//    int height = 480;
//    int done = 0;
//    int imageRad = 20;
//
//    // Allegro variable
//    ALLEGRO_DISPLAY *display = NULL;
//    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
//    ALLEGRO_BITMAP *image = NULL;
//
//    // Program init
//    if (!al_init())
//    {
//        return -1;
//    }
//
//    display = al_create_display(width, height);
//
//    if (!display)
//    {
//        return -1;
//    }
//
//    // Addon init
//    al_install_keyboard();
//    al_init_primitives_addon();
//
//    image = al_create_bitmap(imageRad * 2, imageRad * 2);
//
//    al_set_target_bitmap(image);
//
//    al_draw_filled_rectangle(imageRad, imageRad - 9, imageRad + 10, imageRad - 7, al_map_rgb(255, 0, 0));
//    al_draw_filled_rectangle(imageRad, imageRad + 9, imageRad + 10, imageRad + 7, al_map_rgb(255, 0, 0));
//
//    al_draw_filled_triangle(imageRad - 12, imageRad - 17, imageRad + 12, imageRad, imageRad - 12, imageRad + 17, al_map_rgb(0, 255, 0));
//    al_draw_filled_rectangle(imageRad - 12, imageRad - 2, imageRad + 15, imageRad + 2, al_map_rgb(0, 0, 255));
//
//    al_set_target_bitmap(al_get_backbuffer(display));
//
//    event_queue = al_create_event_queue();
//    al_register_event_source(event_queue, al_get_keyboard_event_source());
//
//    while (!done) {
//        ALLEGRO_EVENT event;
//
//        al_wait_for_event(event_queue, &event);
//
//        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
//        {
//            switch (event.keyboard.keycode) {
//                case ALLEGRO_KEY_ESCAPE:
//                    done = 1;
//                    break;
//            }
//        }
//
//        al_draw_bitmap(image, width / 2, height / 2, 0);
//        al_flip_display();
//        al_clear_to_color(al_map_rgb(0, 0, 0));
//
////        al_draw_bitmap(buffer, fundo, 5, 5);
////        al_draw_pixel(640, 480, al_map_rgb(255, 0, 255));
////        al_rest(5.0f);
//    }
//
//    al_destroy_display(display);
////    al_destroy_bitmap(buffer);
////    al_destroy_bitmap(fundo);
//    return 0;
//}
