#include <stdio.h>
#define N 4

void warshall(int W[N][N]) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                W[i][j] = W[i][j] || (W[i][k] && W[k][j]);
            }
        }
    }
}

void printMatrix(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int W[N][N] = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {1, 0, 1, 0}
    };
    
    printf("Initial Adjacency Matrix:\n");
    printMatrix(W);

    warshall(W);

    printf("\nTransitive Closure Matrix (W):\n");
    printMatrix(W);

    return 0;
}