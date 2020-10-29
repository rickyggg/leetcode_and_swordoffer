class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int dp[m][n];
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          dp[i][j] = 0;
        } else {
          if (i && j)
            dp[i][j] =
                min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
          else
            dp[i][j] = 1;
          res += dp[i][j];
        }
      }
    }
    return res;
  }
};
