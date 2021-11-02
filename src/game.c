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

int is_direction(char direction) {
    return direction == LEFT
        || direction == UP
        || direction == DOWN
        || direction == RIGHT;
}

void move(char direction) {
    if (!is_direction(direction)) return;

    int prox_x = position.x;
    int prox_y = position.y;

    switch (direction) {
        case LEFT:
            prox_y--;
            break;
        case UP:
            prox_x--;
            break;
        case DOWN:
            prox_x++;
            break;
        case RIGHT:
            prox_y++;
            break;
    }

    if (!is_valid(&map, prox_x, prox_y)) return;
    if (!is_empty(&map, prox_x, prox_y)) return;

    walk_in_map(&map, position.x, position.y, prox_x, prox_y);
    position.x = prox_x;
    position.y = prox_y;
}

int main() {
    read_map(&map);
    found_map(&map, &position, HERO);

    do {
        print_map(&map);

        char command;
        scanf(" %c", &command);
        move(command);
    } while (!finish());    

    free_map(&map);

    return 0;
}
