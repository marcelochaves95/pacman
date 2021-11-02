#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'

void space();
int finish();
void move(char direction);
int is_direction(char direction);
void ghosts();
int ghost_ai(int current_x, int current_y, int* destiny_x, int* destiny_y);
void pill_explode(int x, int y, int quantity);
