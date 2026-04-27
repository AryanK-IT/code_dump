#include <stdbool.h>

int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
    }
}

bool letterExistsInSubstring(char *s, char ch, int i, int j)
{
    for (int m = i; m < j; m++)
    {
        if (ch == s[m])
            return true;
        return false;
    }
}