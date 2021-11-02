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

void print_map() {
    for (int i = 0; i < lines; i++)
    {
        printf("%s\n", map[i]);
    }
}

int finish() {
    return 0;
}

void move(char direction) {
    int x;
    int y;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            if (map[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direction)
    {
        case 'a':
            map[x][y - 1] = '@';
            break;
        case 'w':
            map[x - 1][y] = '@';
            break;
        case 's':
            map[x + 1][y] = '@';
            break;
        case 'd':
            map[x][y + 1] = '@';
            break;
    }

    map[x][y] = '.';
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