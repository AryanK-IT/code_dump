#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool letterExistsInSubstring(char *s, char ch, int i, int j) {
    for (int m = i; m < j; m++) {
        if (ch == s[m])
            return true;
    }
    return false;
}

int lengthOfLongestSubstring(char *s) {
    int len = strlen(s);
    int maxLen = 0;

    for (int i = 0; i < len; i++) {
        int j = i;
        while (j < len && !letterExistsInSubstring(s, s[j], i, j)) {
            j++;
        }
        if (j - i > maxLen) {
            maxLen = j - i;
        }
    }
    return maxLen;
}