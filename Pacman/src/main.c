#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

int main()
{
   if (!al_init()) {
      al_show_native_message_box(NULL, "Error", "Error", "Could not init Allegro!", NULL, 0);
   }
   al_init_image_addon();
   ALLEGRO_DISPLAY* disp = al_create_display(800, 600);
   if (!disp) {
      al_show_native_message_box(NULL, "Error", "Error", "Could not create display!", NULL, 0);
   }
   ALLEGRO_BITMAP* bmp = al_load_bitmap("mysha.pcx");
   if (!bmp) {
      al_show_native_message_box(NULL, "Error", "Error", "Could not load bitmap!", NULL, 0);
   }

   al_clear_to_color(al_map_rgb(0, 0, 0));
   al_draw_bitmap(bmp, 0, 0, 0);
   al_flip_display();

   al_rest(5.0);
   return 0;
}
