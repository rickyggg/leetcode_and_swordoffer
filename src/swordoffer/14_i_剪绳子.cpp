class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) return n - 1;
        int dp[n + 1];
        fill(dp, dp + n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            int max = 0;
            for (int j = 1; j <= i / 2; ++j) {
                if (dp[j] * dp[i - j] > max)
                    max = dp[j] * dp[i - j];
                dp[i] = max;
            }
        }
        return dp[n];
    }
};
