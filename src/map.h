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