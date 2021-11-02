#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"

MAP map;
POSITION position;

void space() {
    printf("\n");
}

int finish() {
    return 0;
}

void move(char direction) {
    if (direction != 'a'
        && direction != 'w'
        && direction != 's'
        && direction != 'a')
        return;

    int prox_x = position.x;
    int prox_y = position.y;

    switch (direction) {
        case 'a':
            prox_y--;
            break;
        case 'w':
            prox_x--;
            break;
        case 's':
            prox_x++;
            break;
        case 'd':
            prox_y++;
            break;
    }

    if (prox_x >= map.lines) return;
    if (prox_y >= map.columns) return;
    if (map.matrix[prox_x][prox_y] != '.') return;

    map.matrix[prox_x][prox_y] = '@';
    map.matrix[position.x][position.y] = '.';
    position.x = prox_x;
    position.y = prox_y;
    
}

int main() {
    read_map(&map);
    found_map(&map, &position, '@');

    do {
        print_map(&map);

        char command;
        scanf(" %c", &command);
        move(command);
    } while (!finish());    

    free_map(&map);

    return 0;
}