class Solution {
public:
    int numWays(int n) {
        if (n < 2) return 1;
        if (n == 2) return 2;
        int dp[n];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; ++i) 
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        return dp[n - 1];
    }
};
