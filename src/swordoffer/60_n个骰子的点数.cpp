class Solution {
public:
    vector<double> twoSum(int n) {
        int dp[67];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; ++i)
            dp[i] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 6 * i; j >= i; --j) {
                dp[j] = 0;
                for (int cur = 1; cur <= 6; ++cur) {
                    if (j - cur < i - 1)
                        break;
                    dp[j] += dp[j - cur];
                }
            }
        }
        vector<double> res;
        int all = pow(6, n);
        for (int i = n; i <= 6 * n; ++i)
            res.push_back(dp[i] * 1.0 / all);
        return res;
    }
};
