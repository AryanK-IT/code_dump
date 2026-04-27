#include <stdbool.h>
#include <string.h>

int dp[10001][10001];

bool f(int i, int j, char* s, char* p) {
    if (i < 0 && j < 0)
        return true;

    if (i < 0 && j >= 0)
        return false;

    if (i >= 0 && j < 0) {
        for (int ii = 0; ii <= i; ii++) {
            if (p[ii] != '*')
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (p[i] == s[j] || p[i] == '?')
        return dp[i][j] = f(i - 1, j - 1, s, p);

    if (p[i] == '*') {
        return dp[i][j] = f(i - 1, j, s, p) || f(i, j - 1, s, p);
    }

    return dp[i][j] = false;
}

bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = -1;
        }
    }
    return f(n - 1, m - 1, s, p);
}