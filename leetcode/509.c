#include <stdio.h>
#include <stdlib.h>

// Function to compute nth Fibonacci number using tabulation
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int *dp = (int *)malloc((n + 1) * sizeof(int));
    if (dp == NULL) {
        printf("Memory allocation failed\n");
        return -1; // indicate error
    }

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = dp[n];
    free(dp); // Free allocated memory
    return result;
}