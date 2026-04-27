int numDecodings(char* s) {
    
    int n = strlen(s);
    if (n == 0 || s[0] == '0') return 0;

    int dp[n + 1];
    dp[0] = 1; 
    dp[1] = 1;  

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;

        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];
            
        int two_digit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (two_digit >= 10 && two_digit <= 26)
            dp[i] += dp[i - 2];
    }

    return dp[n];
}