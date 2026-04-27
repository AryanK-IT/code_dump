#include <string.h>
#include <limits.h>
#include <stdbool.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

bool isPalindrome(int i, int j, char *s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int count_p(int i, int n, char *s, int *dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int minCost = INT_MAX;

    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, s))
        {
            int cost = 1 + count_p(j + 1, n, s, dp);
            minCost = min(minCost, cost);
        }
    }
    dp[i] = minCost;
    return dp[i];
}

int minCut(char *s)
{
    int n = strlen(s);
    int *dp = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
    int result = count_p(0, n, s, dp) - 1;

    free(dp);
    return result;
}