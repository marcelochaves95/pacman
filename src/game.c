#include <stdio.h>
#include <stdlib.h>

void space() {
    printf("\n");
}

int main() {
    char map[5][10 + 1];

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

    for (int i = 0; i < 5; i++)
    {
        fscanf(file, "%s", map[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", map[i]);
    }
    
    fclose(file);

    return 0;
}