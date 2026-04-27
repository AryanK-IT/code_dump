#include <stdio.h>
#include <stdlib.h>

int maxCoins(int *arr, int arrSize)
{
    int newArrSize = arrSize + 2;

    int *newArr = (int *)calloc(newArrSize, sizeof(int));

    newArr[0] = 1;
    newArr[arrSize - 1] = 1;

    for (int i = 1; i < newArrSize; i++)
    {
        newArr[i] = arr[i - 1];
    }

    int **dp = (int **)malloc(newArrSize * sizeof(int *));
    for (int i = 0; i < newArrSize; i++)
    {
        dp[i] = (int *)calloc(arrSize,sizeof(int));
    }
    
    for (int len = 2; len < newArrSize; len++) {
        for (int left = 0; left < newArrSize - len; left++) {
            int right = left + len;
            for (int k = left + 1; k < right; k++) {
                int total = newArr[left] * newArr[k] * newArr[right]
                          + dp[left][k] + dp[k][right];
                if (total > dp[left][right]) {
                    dp[left][right] = total;
                }
            }
        }
    }

    int result = dp[0][newArrSize - 1];

}