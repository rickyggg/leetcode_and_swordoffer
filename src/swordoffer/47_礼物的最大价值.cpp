class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int dp[col];
        memset(dp, 0, sizeof(dp));
        dp[0] = grid[0][0];
        for (int j = 1; j < col; ++j)
            dp[j] = dp[j - 1] + grid[0][j];
        for (int i = 1; i < row; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < col; ++j) {
                dp[j] = max(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[col - 1];
    }
};
