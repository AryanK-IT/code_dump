#include <stdio.h>
#include <stdlib.h>

int maxCoins(int* nums, int numsSize) {
    int n = numsSize + 2;
    int* newNums = (int*)calloc(n, sizeof(int));
    newNums[0] = 1;
    newNums[n - 1] = 1;
    for (int i = 0; i < numsSize; i++) {
        newNums[i + 1] = nums[i];
    }

    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
    }

    for (int len = 2; len < n; len++) {
        for (int left = 0; left < n - len; left++) {
            int right = left + len;
            for (int k = left + 1; k < right; k++) {
                int total = newNums[left] * newNums[k] * newNums[right]
                          + dp[left][k] + dp[k][right];
                if (total > dp[left][right]) {
                    dp[left][right] = total;
                }
            }
        }
    }

    int result = dp[0][n - 1];

    for (int i = 0; i < n; i++) free(dp[i]);
    free(dp);
    free(newNums);

    return result;
}