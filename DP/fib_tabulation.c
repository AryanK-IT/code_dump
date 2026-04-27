#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int *fibo(int n)
{
    int result;
    int *arr = (int *)malloc((n + 1) * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }

    memset(arr, 0, (n + 1) * sizeof(int));
    arr[1] = 1;

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr;
}
int fib(int n)
{
    int arr[] = fibo(n);
    return arr[n];
}