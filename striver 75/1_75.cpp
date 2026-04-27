int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{

    int map[numsSize];
    int result[returnSize];
    for (int i = 0; i < numsSize; i++)
    {
        int value_to_look_in_hashmap = target - nums[i];
        for (int j = 0; j < numsSize; j++)
        {
            if (value_to_look_in_hashmap == map[j])
            {
                result[0] = j;
                result[1] = i;
                return result;
            }
        }
        map[i] = nums[i];
    }
}
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = 4;
    
    int returnSize = 2; 

    cout << "Starting twoSum..." << endl;

    int *result = twoSum(nums, numsSize, target, &returnSize);

    if (result != nullptr) {
        cout << "Indices found: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}