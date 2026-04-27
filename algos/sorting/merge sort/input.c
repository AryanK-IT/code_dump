#include <stdio.h>
#include <stdlib.h>

void createInputFile() {
    FILE* f = fopen("input.dat", "wb");
    if (!f) {
        printf("Error: Cannot create input.dat\n");
        return;
    }


    int n = 300 + rand() % 201;
    fwrite(&n, sizeof(int), 1, f);

    for (int i = 0; i < n; i++) {
        int value = rand() % 1000;
        fwrite(&value, sizeof(int), 1, f);
    }

    fclose(f);
    printf("input.dat created with %d random integers.\n", n);
}

int main() {
    createInputFile();
    return 0;
}
