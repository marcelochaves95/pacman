#include <stdio.h>
#include <stdlib.h>

char** map;
int lines;
int columns;

void space() {
    printf("\n");
}

int main() {
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
    printf("Lines: %d | Columns: %d", lines, columns);
    space();

    map = malloc(sizeof(char*) * lines);
    for (int i = 0; i < lines; i++)
    {
        map[i] = malloc(sizeof(char) * (columns + 1));
    }

    for (int i = 0; i < lines; i++)
    {
        fscanf(file, "%s", map[i]);
    }

    for (int i = 0; i < lines; i++)
    {
        printf("%s\n", map[i]);
    }

    fclose(file);

    for (int i = 0; i < lines; i++)
    {
        free(map[i]);
    }

    free(map);

    return 0;
}