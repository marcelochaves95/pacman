#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

// Command to run
// gcc -o Pacman main.c -lallegro -lallegro_image -lallegro_dialog -lallegro_main
// ./Pacman

ALLEGRO_BITMAP* load_bitmap_at_size(const char* file_name, int width, int height) {
    ALLEGRO_BITMAP* resized_bitmap;
    ALLEGRO_BITMAP* loaded_bitmap;
    ALLEGRO_BITMAP* previous_target;

    // Create a temporary bitmap of size we want
    resized_bitmap = al_create_bitmap(width, height);
    if (!resized_bitmap) return NULL;

    // Load the bitmap at the original size
    loaded_bitmap = al_load_bitmap(file_name);
    if (!loaded_bitmap) {
        al_destroy_bitmap(resized_bitmap);
        return NULL;
    }

    // Set the target bitmap to the resized bmp
    previous_target = al_get_target_bitmap();
    al_set_target_bitmap(resized_bitmap);

    // Copy the loaded bitmap to the resized bmp
    al_draw_scaled_bitmap(loaded_bitmap,
        0, 0,                                // source origin
        al_get_bitmap_width(loaded_bitmap),  // source width
        al_get_bitmap_height(loaded_bitmap), // source height
        0, 0,                                // target origin
        width, height,                       // target dimensions
        0                                    // flags
    );

    // Restore the previous target and clean up
    al_set_target_bitmap(previous_target);
    al_destroy_bitmap(loaded_bitmap);

    return resized_bitmap;
}

int width = 677;
int height = 665;
int is_running = 1;

int main() {
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_BITMAP* bitmap = NULL;
    
    al_init();
    display = al_create_display(width * 2, height * 2);
    
    queue = al_create_event_queue();
    al_install_keyboard();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_init_image_addon();

    //bitmap = al_load_bitmap("../img/fundo.bmp");
    bitmap = load_bitmap_at_size("../img/fundo.bmp", width * 2, height * 2);
    //assert(bitmap != NULL);

    float x = 0;
    int width = al_get_display_width(display);
    
    while (is_running) {
        al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
        al_draw_bitmap(bitmap, 0, 0, 0);
        
        //al_draw_scaled_bitmap(bitmap, 0, 0, width * 2, height * 2, 0, 0, width * 2, height * 2, 0);
        
        al_flip_display();
        if (x > width) {
            x = -al_get_bitmap_width(bitmap);
        }
        
        ALLEGRO_EVENT event;
        if (!al_is_event_queue_empty(queue)) {
            al_wait_for_event(queue, &event);
            if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                is_running = 0;
            }
        }
    }

    al_destroy_display(display);
    al_uninstall_keyboard();
    al_destroy_bitmap(bitmap);

    return 0;
}
