#include <stdio.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{

    int *result = (int *)malloc(2 * sizeof(int));
}
int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = 4;

    int returnSize = 2;

    printf("Starting twoSum...\n");

    int *result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL)
    {
        printf("Indices found: [%d, %d]\n", result[0], result[1]);
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}