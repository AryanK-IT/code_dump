/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    int candidates[] = {2, 3, 6, 7};
    int candidatesSize = 4;
    int target = 7;

    int returnSize;
    int *returnColumnSizes;

    int **result = combinationSum(
        candidates,
        candidatesSize,
        target,
        &returnSize,
        &returnColumnSizes);

    printf("Combinations:\n");
    for (int i = 0; i < returnSize; i++)
    {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1)
                printf(", ");
        }
        printf("]\n");
    }

    // Free memory
    for (int i = 0; i < returnSize; i++)
    {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}

int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    int num_of_combinations = 0;
    for (int i = 0; i < candidatesSize; i++)
    {
        if (candidates[i] == target)
        {
            returnColumnSizes[num_of_combinations] = candidates[i];
            num_of_combinations++;
        }

        int test = 0;
        while (test < target)
        {
            int *returnSize = (int *)malloc(sizeof(int));
            
            if (test == target)
            {
                returnColumnSizes[num_of_combinations] = candidates[i];
                num_of_combinations++;
            }
            test += candidates[i];
        }

        int test = 0;

        for (int m = 0; m < candidatesSize; m++)
        {
            for (int n = 0; n < candidatesSize; n++)
            {
            }
        }
    }
}