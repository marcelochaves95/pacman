#include <stdio.h>
#include "map.h"
#include "game.h"

char draw_wall[4][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char draw_ghost[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char draw_character[4][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char draw_pill[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char draw_empty[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

void print_part(char draw[4][7], int part) {
    printf("%s", draw[part]);
}

void print_map(MAP* map) {
    for (int i = 0; i < map->lines; i++) {
        for (int part = 0; part < 4; part++) {
            for (int j = 0; j < map->columns; j++) {
                switch (map->matrix[i][j]) {
                    case GHOST:
                        print_part(draw_ghost, part);
                        break;
                    case CHARACTER:
                        print_part(draw_character, part);
                        break;
                    case PILL:
                        print_part(draw_pill, part);
                        break;
                    case VERTICAL_WALL:
                    case HORIZONTAL_WALL:
                        print_part(draw_wall, part);
                        break;
                    case EMPTY:
                        print_part(draw_empty, part);
                        break;
                }
            }
            space();    
        }
    }
}

