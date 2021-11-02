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
    map.matrix[position.x][position.y] = '.';
    switch (direction) {
        case 'a':
            map.matrix[position.x][position.y - 1] = '@';
            position.y--;
            break;
        case 'w':
            map.matrix[position.x - 1][position.y] = '@';
            position.x--;
            break;
        case 's':
            map.matrix[position.x + 1][position.y] = '@';
            position.x++;
            break;
        case 'd':
            map.matrix[position.x][position.y + 1] = '@';
            position.y++;
            break;
    }
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