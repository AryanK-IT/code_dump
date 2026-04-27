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
    int **result = NULL;
    *returnSize = 0;
    *returnColumnSizes == NULL;

    int temp[150];
    int stack[150];
    int top = 0;
    int sum = 0;

    stack[0] = 0;

    while (top >= 0)
    {
        int i = stack[top];

        if (sum == target)
        {
            result = realloc(result, sizeof(int *) * (*returnSize + 1));
            returnColumnSizes = realloc(returnColumnSizes, sizeof(int *) * (*returnSize + 1));

            result[*returnSize] = mallloc(sizeof(int *) * top);
            
        }
    }
}