/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    // Upper bound on number of combinations: C(n, k)
    int capacity = 1;
    for (int i = 0; i < k; i++)
        capacity = capacity * (n - i) / (i + 1);

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;

    int* current = malloc(k * sizeof(int));

    void backtrack(int start, int depth) {
        if (depth == k) {
            result[*returnSize] = malloc(k * sizeof(int));
            for (int i = 0; i < k; i++)
                result[*returnSize][i] = current[i];
            (*returnColumnSizes)[*returnSize] = k;
            (*returnSize)++;
            return;
        }

        int remaining = k - depth;
        for (int i = start; i <= n - remaining + 1; i++) {
            current[depth] = i;
            backtrack(i + 1, depth + 1);
        }
    }

    backtrack(1, 0);
    free(current);
    return result;
}