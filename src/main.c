#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

// Command to run
// gcc -o Pacman main.c -lallegro -lallegro_image -lallegro_dialog -lallegro_main
// ./Pacman

struct obj {
    int wx;
    int wy;
    int x;
    int y;
    int w;
    int h;
    int dir;
};

struct obj p = { 42, 0, 13, 23, 42, 44, 2 };

ALLEGRO_BITMAP* load_bitmap_at_size(const char* file_name, int width, int height);
void sair();
void mapa(int mod);

int width = 1048;
int height = 670;
int is_running = 1;

const int LENGTH_Y = 31;
const int LENGTH_X = 28;
int map [LENGTH_Y][LENGTH_X];

ALLEGRO_BITMAP* buffer = NULL;
ALLEGRO_BITMAP* itens = NULL;
ALLEGRO_BITMAP* fundo = NULL;

int main() {
    al_init_image_addon();

    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* event_queue;
    
    al_init();
    display = al_create_display(width, height);
    al_set_window_title(display, "Pacman");

    event_queue = al_create_event_queue();
    al_install_keyboard();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_init_image_addon();

    fundo = load_bitmap_at_size("../img/fundo.bmp", width, height);
    itens = load_bitmap_at_size("../img/itens2.bmp", 8, 8);
    //itens = al_load_bitmap("");
    assert(fundo != NULL);

    float x = 0;
    int width = al_get_display_width(display);
    
    mapa(1);
    while (is_running) {
        al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
        al_draw_bitmap(fundo, 0, 0, 0);
        mapa(0);
        al_flip_display();
        if (x > width) {
            x = -al_get_bitmap_width(fundo);
        }

        if (!al_is_event_queue_empty(event_queue)) {
            ALLEGRO_EVENT event;
            al_wait_for_event(event_queue, &event);

            if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                is_running = 0;
            }
        }
    }

    al_destroy_display(display);
    al_uninstall_keyboard();
    //al_destroy_bitmap(fundo);
    al_destroy_bitmap(itens);

    return 0;
}

//END_OF_MAIN();

ALLEGRO_BITMAP* load_bitmap_at_size(const char* file_name, int width, int height) {
    ALLEGRO_BITMAP* resized_bitmap;
    ALLEGRO_BITMAP* loaded_bitmap;
    ALLEGRO_BITMAP* previous_target;

    resized_bitmap = al_create_bitmap(width, height);
    if (!resized_bitmap) return NULL;

    loaded_bitmap = al_load_bitmap(file_name);
    if (!loaded_bitmap) {
        al_destroy_bitmap(resized_bitmap);
        return NULL;
    }

    previous_target = al_get_target_bitmap();
    al_set_target_bitmap(resized_bitmap);

    al_draw_scaled_bitmap(loaded_bitmap,
        0, 0,
        al_get_bitmap_width(loaded_bitmap),
        al_get_bitmap_height(loaded_bitmap),
        0, 0,
        width, height,
        0
    );

    al_set_target_bitmap(previous_target);
    al_destroy_bitmap(loaded_bitmap);

    return resized_bitmap;
}

void mapa(int mod) {
    int i, j;

    char mp[LENGTH_Y][LENGTH_X] = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, },
        { 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, },
        { 1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 1, },
        { 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, },
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, },
        { 1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, },
        { 1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, },
        { 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, },
        { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, },
        { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, },
        { 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, },
        { 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, },
        { 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, },
        { 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, },
        { 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, },
        { 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, },
        { 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, },
        { 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, },
        { 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, },
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, },
        { 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, },
        { 1, 3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3, 1, },
        { 1, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 1, },
        { 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, },
        { 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, },
        { 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 1, },
        { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, },
        { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, },
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, }
    };

    for (int i = 0; i < LENGTH_Y; i++) {
        for (int j = 0; j < LENGTH_X; j++) {
            if (mod) {
                map[i][j] = mp[i][j];
            }

            if (map[i][j] == 2)
            {
                al_draw_bitmap(itens, j * LENGTH_X + 5, i * 21 + 5, 0);
                
                // Pontos
                //masked_blit(itens, buffer, 3, 10, j * LENGTH_X + 10, 21 + 16, 6, 6);
            }
        }
    }
}

void sair() {
    is_running = 0;
}

//END_OF_FUNCTION(sair);