#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "game.h"

void walk_in_map(MAP* map, int x_origin, int y_origin, int x_destiny, int y_destiny) {
    char character = map->matrix[x_origin][y_origin];
    map->matrix[x_destiny][y_destiny] = character;
    map->matrix[x_origin][y_origin] = '.';
}

int is_empty(MAP* map, int x, int y) {
    return map->matrix[x][y] == '.';
}

int is_valid(MAP* map, int x, int y) {
    if (x >= map->lines) return 0;
    if (y >= map->columns) return 0;

    return 1;
}
void found_map(MAP* map, POSITION* position, char c) {
    for (int i = 0; i < map->lines; i++) {
        for (int j = 0; j < map->columns; j++) {
            if (map->matrix[i][j] == c) {
                position->x = i;
                position->y = j;
                break;
            }
        }
    }
}

void free_map(MAP* map) {
    for (int i = 0; i < map->lines; i++) {
        free(map->matrix[i]);
    }

    free(map->matrix);
}

void read_map(MAP* map) {
    char filename[] = "../files/map.txt";
    char* path = realpath(filename, NULL);
    if (path == NULL) {
        printf("Database not available.\n");
        space();
        exit(1);
    }

    FILE* file = fopen(path, "r");
    if (file == 0) {
        printf("Database not available.\n");
        space();
        exit(1);
    }

    fscanf(file, "%d %d", &map->lines, &map->columns);

    alloc_map(map);

    for (int i = 0; i < map->lines; i++) {
        fscanf(file, "%s", map->matrix[i]);
    }

    fclose(file);
}

void alloc_map(MAP* map) {
    map->matrix = malloc(sizeof(char*) * map->lines);
    for (int i = 0; i < map->lines; i++) {
        map->matrix[i] = malloc(sizeof(char) * (map->columns + 1));
    }
}

void print_map(MAP* map) {
    for (int i = 0; i < map->lines; i++) {
        printf("%s\n", map->matrix[i]);
    }
}