#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4
#define DP_ROWS (1 << N)

int dp[DP_ROWS][N];

int cost_matrix[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

const int VISITED_ALL = (1 << N) - 1;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int mask, int pos) {
    if (mask == VISITED_ALL) {
        return cost_matrix[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int min_cost = INT_MAX;

    for (int city = 0; city < N; city++) {
        if (!(mask & (1 << city))) {
            int new_cost = cost_matrix[pos][city] + tsp(mask | (1 << city), city);

            min_cost = min(min_cost, new_cost);
        }
    }

    return dp[mask][pos] = min_cost;
}

int main() {
    for (int i = 0; i < DP_ROWS; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    int min_tour_cost = tsp(1, 0);

    printf("Minimum cost for the TSP tour: %d\n", min_tour_cost);

    return 0;
}