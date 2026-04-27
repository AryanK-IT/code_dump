#include <stdio.h>
#include <stdlib.h>

void readOutputFile() {
    FILE* f = fopen("output.dat", "rb");
    if (!f) {
        printf("Error: Cannot open output.dat\n");
        return;
    }

    int n;
    fread(&n, sizeof(int), 1, f);

    int* arr = (int*)malloc(n * sizeof(int));
    fread(arr, sizeof(int), n, f);
    fclose(f);

    printf("Contents of output.dat:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
}

int main() {
    readOutputFile();
    return 0;
}
