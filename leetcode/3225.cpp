#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        // prefix[c][i] = sum of first i elements in column c
        vector<vector<long long>> prefix(n, vector<long long>(n + 1, 0));

        for (int c = 0; c < n; c++) {
            for (int r = 0; r < n; r++) {
                prefix[c][r + 1] = prefix[c][r] + grid[r][c];
            }
        }

        vector<long long> prevPick(n + 1, 0);
        vector<long long> prevSkip(n + 1, 0);

        for (int col = 1; col < n; col++) {
            vector<long long> currPick(n + 1, 0);
            vector<long long> currSkip(n + 1, 0);

            for (int curr = 0; curr <= n; curr++) {
                for (int prev = 0; prev <= n; prev++) {
                    if (curr > prev) {
                        long long score =
                            prefix[col - 1][curr] - prefix[col - 1][prev];

                        currPick[curr] = max(
                            currPick[curr],
                            prevSkip[prev] + score);

                        currSkip[curr] = max(
                            currSkip[curr],
                            prevSkip[prev] + score);
                    } else {
                        long long score =
                            prefix[col][prev] - prefix[col][curr];

                        currPick[curr] = max(
                            currPick[curr],
                            prevPick[prev] + score);

                        currSkip[curr] = max(
                            currSkip[curr],
                            prevPick[prev]);
                    }
                }
            }

            prevPick = currPick;
            prevSkip = currSkip;
        }

        return *max_element(prevPick.begin(), prevPick.end());
    }
};