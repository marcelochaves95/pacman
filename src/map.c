#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "game.h"

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