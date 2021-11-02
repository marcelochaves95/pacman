#include <stdio.h>
#include <stdlib.h>
#include "game.h"

MAP map;

void space() {
    printf("\n");
}

void free_map() {
    for (int i = 0; i < map.lines; i++)
    {
        free(map.matrix[i]);
    }

    free(map.matrix);
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

    fscanf(file, "%d %d", &map.lines, &map.columns);

    alloc_map();

    for (int i = 0; i < map.lines; i++)
    {
        fscanf(file, "%s", map.matrix[i]);
    }

    fclose(file);
}

void alloc_map() {
    map.matrix = malloc(sizeof(char*) * map.lines);
    for (int i = 0; i < map.lines; i++) {
        map.matrix[i] = malloc(sizeof(char) * (map.columns + 1));
    }
}

void print_map() {
    for (int i = 0; i < map.lines; i++)
    {
        printf("%s\n", map.matrix[i]);
    }
}

int finish() {
    return 0;
}

void move(char direction) {
    int x;
    int y;

    for (int i = 0; i < map.lines; i++) {
        for (int j = 0; j < map.columns; j++) {
            if (map.matrix[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direction)
    {
        case 'a':
            map.matrix[x][y - 1] = '@';
            break;
        case 'w':
            map.matrix[x - 1][y] = '@';
            break;
        case 's':
            map.matrix[x + 1][y] = '@';
            break;
        case 'd':
            map.matrix[x][y + 1] = '@';
            break;
    }

    map.matrix[x][y] = '.';
}

int main() {
    read_map();

    do {
        print_map();

        char command;
        scanf(" %c", &command);
        move(command);
    } while (!finish());    

    free_map();

    return 0;
}