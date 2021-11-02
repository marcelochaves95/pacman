#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"

MAP map;

void space() {
    printf("\n");
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
    read_map(&map);

    do {
        print_map(&map);

        char command;
        scanf(" %c", &command);
        move(command);
    } while (!finish());    

    free_map(&map);

    return 0;
}