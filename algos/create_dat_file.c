#include <stdio.h>

int main() {
    int graph[9][9] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    FILE *file;
    int V = 9; 

    file = fopen("inUnAdjMat.dat", "w");

    if (file == NULL) {
        printf("Error: Could not create or open the file 'inUnAdjMat.dat'.\n");
        return 1; 
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fprintf(file, "%d ", graph[i][j]);
        }
        fprintf(file, "\n"); 
    }

    fclose(file);

    printf("Successfully created and wrote to 'inUnAdjMat.dat'.\n");

    return 0;
}