#include <stdio.h>
#include <stdlib.h>
#include "game.h"

struct map m;

void space() {
    printf("\n");
}

void free_map() {
    for (int i = 0; i < m.lines; i++)
    {
        free(m.matrix[i]);
    }

    free(m.matrix);
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

    fscanf(file, "%d %d", &m.lines, &m.columns);

    alloc_map();

    for (int i = 0; i < m.lines; i++)
    {
        fscanf(file, "%s", m.matrix[i]);
    }

    fclose(file);
}

void alloc_map() {
    m.matrix = malloc(sizeof(char*) * m.lines);
    for (int i = 0; i < m.lines; i++) {
        m.matrix[i] = malloc(sizeof(char) * (m.columns + 1));
    }
}

void print_map() {
    for (int i = 0; i < m.lines; i++)
    {
        printf("%s\n", m.matrix[i]);
    }
}

int finish() {
    return 0;
}

void move(char direction) {
    int x;
    int y;

    for (int i = 0; i < m.lines; i++) {
        for (int j = 0; j < m.columns; j++) {
            if (m.matrix[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direction)
    {
        case 'a':
            m.matrix[x][y - 1] = '@';
            break;
        case 'w':
            m.matrix[x - 1][y] = '@';
            break;
        case 's':
            m.matrix[x + 1][y] = '@';
            break;
        case 'd':
            m.matrix[x][y + 1] = '@';
            break;
    }

    m.matrix[x][y] = '.';
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