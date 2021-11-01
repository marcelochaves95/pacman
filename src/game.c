#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char** map;
int lines;
int columns;

void space() {
    printf("\n");
}

void free_map() {
    for (int i = 0; i < lines; i++)
    {
        free(map[i]);
    }

    free(map);
}

void read_map() {
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

    fscanf(file, "%d %d", &lines, &columns);

    alloc_map();

    for (int i = 0; i < lines; i++)
    {
        fscanf(file, "%s", map[i]);
    }

    fclose(file);
}

void alloc_map() {
    map = malloc(sizeof(char*) * lines);
    for (int i = 0; i < lines; i++) {
        map[i] = malloc(sizeof(char) * (columns + 1));
    }
}

int main() {
    read_map();

    for (int i = 0; i < lines; i++)
    {
        printf("%s\n", map[i]);
    }

    free_map();

    return 0;
}