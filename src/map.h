#define HERO '@'
#define EMPTY '.'
#define VERTICAL_LIMIT '|'
#define HORIZONTAL_LIMIT '-'

struct map {
    char** matrix;
    int lines;
    int columns;
};

typedef struct map MAP;

struct position {
    int x;
    int y;
};

typedef struct position POSITION;

void free_map(MAP* map);
void read_map(MAP* map);
void alloc_map(MAP* map);
void print_map(MAP* map);
void found_map(MAP* map, POSITION* position, char c);
int is_valid(MAP* map, int x, int y);
int is_empty(MAP* map, int x, int y);
void walk_in_map(MAP* map, int x_origin, int y_origin, int x_destiny, int y_destiny);
