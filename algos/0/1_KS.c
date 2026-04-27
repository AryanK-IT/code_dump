#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } 
            else if (weights[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } 
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);

    printf("Items:\n");
    for (int i = 0; i < n; i++) {
        printf("  Item %d: Value = %d, Weight = %d\n", i + 1, values[i], weights[i]);
    }
    printf("Knapsack Capacity (W): %d\n", W);
    
    int max_value = knapSack(W, weights, values, n);
    
    printf("\nMaximum value that can be obtained: %d\n", max_value);
    
    return 0;
}