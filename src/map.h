struct map {
    char** matrix;
    int lines;
    int columns;
};

typedef struct map MAP;

void free_map(MAP* map);
void read_map(MAP* map);
void alloc_map(MAP* map);
void print_map(MAP* map);