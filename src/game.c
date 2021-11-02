#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "map.h"

MAP map;
POSITION position;
int has_pill = 0;

int ghost_ai(int current_x, int current_y, int* destiny_x, int* destiny_y) {
    int options[4][2] = {
        { current_x, current_y + 1},
        { current_x + 1, current_y},
        { current_x, current_y - 1},
        { current_x - 1, current_y}
    };

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int position = rand() % 4;
        if (can_move(&map, GHOST, options[position][0], options[position][1])) {
            *destiny_x = options[position][0];
            *destiny_y = options[position][1];

            return 1;
        }
    }

    return 0;
}

void ghosts() {
    MAP copy;
    copy_map(&map, &copy);

    for (int i = 0; i < copy.lines; i++) {
        for (int j = 0; j < copy.columns; j++) {
            if (copy.matrix[i][j] == GHOST) {
                int destiny_x;
                int destiny_y;

                int found = ghost_ai(i, j, &destiny_x, &destiny_y);
                if (found) {
                    walk_in_map(&map, i, j, destiny_x, destiny_y);
                }
            }
        }
    }

    free_map(&copy);
}

void space() {
    printf("\n");
}

int finish() {
    POSITION pos;
    int pacman = found_map(&map, &pos, CHARACTER);
    return !pacman;
}

int is_direction(char direction) {
    return direction == UP
        || direction == DOWN
        || direction == LEFT
        || direction == RIGHT;
}

void move(char direction) {
    if (!is_direction(direction)) return;

    int prox_x = position.x;
    int prox_y = position.y;

    switch (direction) {
        case UP:
            prox_x--;
            break;
        case DOWN:
            prox_x++;
            break;
        case LEFT:
            prox_y--;
            break;
        case RIGHT:
            prox_y++;
            break;
    }

    if (!can_move(&map, CHARACTER, prox_x, prox_y)) return;

    if (is_character(&map, PILL, prox_x, prox_y)) {
        has_pill = 1;
    }

    walk_in_map(&map, position.x, position.y, prox_x, prox_y);
    position.x = prox_x;
    position.y = prox_y;
}

void pill_explode(int x, int y, int quantity) {
    if (quantity == 0) return;
    if (!is_valid(&map, x, y + 1)) return;
    if (is_wall(&map, x, y + 1)) return;

    map.matrix[x][y + 1] = EMPTY;
    pill_explode(x, y + 1, quantity - 1);
}

int main() {
    read_map(&map);
    found_map(&map, &position, CHARACTER);

    do {
        printf("Has pill: %s\n", has_pill ? "YES" : "NO");
        print_map(&map);

        char command;
        scanf(" %c", &command);
        move(command);
        if (command == BOMB) {
            pill_explode(position.x, position.y, 3);
        }

        ghosts();
    } while (!finish());    

    free_map(&map);

    return 0;
}
