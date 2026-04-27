#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int P[], int n) {
    int M[n][n];
    int i, j, k, length, cost;

    for (i = 1; i < n; i++) {
        M[i][i] = 0;
    }

    for (length = 2; length < n; length++) {
        for (i = 1; i < n - length + 1; i++) {
            j = i + length - 1;
            M[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                cost = M[i][k] + M[k + 1][j] + P[i - 1] * P[k] * P[j];
                
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                }
            }
        }
    }
    
    return M[1][n - 1];
}

int main() {
    int P[] = {30, 35, 15, 5, 10, 20};
    int n = sizeof(P) / sizeof(P[0]);

    printf("Matrix Dimensions (P): {");
    for(int i = 0; i < n; i++) {
        printf("%d%s", P[i], (i < n - 1) ? ", " : "");
    }
    printf("}\n");

    int min_cost = matrixChainOrder(P, n);
    
    printf("Minimum number of scalar multiplications is: %d\n", min_cost);

    return 0;
}