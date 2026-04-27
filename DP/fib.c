#include <stdio.h>
#define MAX 100

int fib(int n, int memo[])
{
    if (memo[n] != -1)
        return memo[n];
    if (n <= 2)
        return 1;
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}
int main()
{
    int n;
    printf("Enter a number (<= %d): ", MAX - 1);
    scanf("%d", &n);

    if (n >= MAX || n < 0)
    {
        printf("Invalid input. n must be between 0 and %d\n", MAX - 1);
        return 1;
    }
    int memo[MAX];
    for (int i = 0; i < MAX; i++)
    {
        memo[i] = -1;
    }
    printf("Fibonacci number at position %d is: %d\n", n, fib(n, memo));
    printf("%d\n", fib(10,memo));
    printf("%d\n", fib(40,memo));
    printf("%d\n", fib(50,memo));

    return 0;
}