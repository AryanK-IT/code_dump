int maxCoins(int *nums, int numsSize)
{
    int original[505];
    original[0] = 1;
    for (int i = 1; i <= numsSize; i++)
        original[i] = nums[i - 1];
    original[numsSize + 1] = 1;
    
    return maxCoinsUtil(original, 1, numsSize);
}

int f(int *nums, int numsSize, int left, int right)
{
    if (left > right)
        return 0;

    int maxVal = 0;
    for (int i = left; i < right; i++)
    {
        int coins = nums[i - 1] * nums[i] * nums[i + 1] + f(nums, numsSize, left, i - 1) + f(nums, numsSize, i + 1, right);

        maxVal = maxVal > coins ? maxVal : coins;
    }
    return maxVal;
}