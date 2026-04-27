#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100

int gridTrav(int m, int n, int memo[MAX_ROWS][MAX_COLS]);
int main()
{
    int memo[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            memo[i][j] = -1;
        }
    }
    printf("%d\n", gridTrav(2, 2, memo));
    printf("%d\n", gridTrav(2, 3, memo));
    printf("%d\n", gridTrav(18, 18, memo));
    return 0;
}

int gridTrav(int m, int n, int memo[MAX_ROWS][MAX_COLS])
{
    if (m == 0 || n == 0)
        return 0;
    if (m == 1 && n == 1)
        return 1;
    if (memo[m][n] != -1)
        return memo[m][n];
    memo[m][n] = gridTrav(m - 1, n, memo) + gridTrav(m, n - 1, memo);
    return memo[m][n];
}