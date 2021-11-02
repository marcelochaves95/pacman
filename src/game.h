void space();
void free_map();
void read_map();
void alloc_map();
void print_map();
int finish();
void move(char direction);

struct map {
    char** matrix;
    int lines;
    int columns;
};

typedef struct map MAP;
