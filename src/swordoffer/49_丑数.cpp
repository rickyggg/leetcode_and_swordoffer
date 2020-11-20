class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1) return 0;
        vector<int> dp(n);
        int a = 0, b = 0, c = 0;
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int a2 = dp[a] * 2, b3 = dp[b] * 3, c5 = dp[c] * 5;
            dp[i] = min(a2, min(b3, c5));
            if (dp[i] == a2) ++a;
            if (dp[i] == b3) ++b;
            if (dp[i] == c5) ++c;
        }
        return dp[n - 1];
    }
};
