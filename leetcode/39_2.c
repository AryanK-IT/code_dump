#include <stdlib.h>

void backtrack(
    int *candidates,
    int candidatesSize,
    int target,
    int start,
    int *temp,
    int tempSize,
    int ***result,
    int *returnSize,
    int **returnColumnSizes)
{
    if (target == 0)
    {
        (*result) = realloc(*result, sizeof(int *) * (*returnSize + 1));
        (*returnColumnSizes) = realloc(*returnColumnSizes, sizeof(int) * (*returnSize + 1));

        (*result)[*returnSize] = malloc(sizeof(int) * tempSize);
        for (int i = 0; i < tempSize; i++)
        {
            (*result)[*returnSize][i] = temp[i];
        }

        (*returnColumnSizes)[*returnSize] = tempSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++)
    {
        if (candidates[i] > target)
            continue;

        temp[tempSize] = candidates[i];

        backtrack(
            candidates,
            candidatesSize,
            target - candidates[i],
            i,
            temp,
            tempSize + 1,
            result,
            returnSize,
            returnColumnSizes);
    }
}

int **combinationSum(
    int *candidates,
    int candidatesSize,
    int target,
    int *returnSize,
    int **returnColumnSizes)
{
    int **result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    int temp[150];

    backtrack(
        candidates,
        candidatesSize,
        target,
        0,
        temp,
        0,
        &result,
        returnSize,
        returnColumnSizes);

    return result;
}
