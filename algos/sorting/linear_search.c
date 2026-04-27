#include <stdio.h>

int linearSearch(int arr[], int n, int target)
{
    for (int index = 0; index < n; index++)
    {
        if (arr[index] == target)
            return index;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int target = 10;

    int result = linearSearch(arr, n, target);
    if (result != 1)
        printf("Element found at index : %d\n", result);
    else
        printf("Element not found in array.\n");
    return 0;
}